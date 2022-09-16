#include "includes.h"
#include "custom-layer.hpp"


/*
  Here we define the hook function and the trampoline function, with
  the first being a global variable with a function type, and the other
  is an actual function. On Android we do not need to specify the calling 
  convention of function hooks, we simply add `this` as the first argument
  and call it `self`. For example:
  
		MenuLayer::init() 
	
	would be
	
	MenuLayer_init(MenuLayer* self)
		
	another example:
	
		PlayLayer::init(GJGameLevel* level)
	
	would be
	
		PlayLayer_init(PlayLayer* self, GJGameLevel* level)
		
	PS: If functions are static they may not need the extra `this`/`self` argument
	(create functions are usually static)
*/


bool (*MenuLayer_init)(MenuLayer*);
bool MenuLayer_initH(MenuLayer* self) {

	/*
      In cocos2d-x, init functions return a boolean, which is false if
      the initialization went wrong, so here we check for it. most of the time
      gd just crashes if an init function goes wrong so this is kinda useless,
      except for the part where we return true at the end
    */
	
    if (!MenuLayer_init(self)) return false;


/*
      Note that we're using the one without the -uhd and -hd suffix; which is
      because gd deals with selecting the right resolution texture for us.
      Note that this texture is also its own file in the assets folder inside the APK,
      meaning you access it via CCSprite::create
    */
	
    auto sprite = CCSprite::create("dialogIcon_017.png");
	
	
	/*
      Also note that this one is different, as the texture is contained within a
      spritesheet, so for that we use CCSprite::createWithSpriteFrameName
      For finding the name of a texture that is inside a spritesheet, you can either
      look at the .plist file directly, or use Absolute's texture splitter.
    */

    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");

/*
      As with every CCNode, you can set it's position, scale, rotation, etc.
      cocos2d-x's position system is based off the bottom left corner of your screen,
      and the values aren't in pixels (sometimes they aren't even consistent), so
      positioning may require a lot of trial and error.
    */

    sprite->setPosition({100, 100});
    sprite->setScale(0.5f);
    // make sure to actually add it to the layer, otherwise nothing will show up
    self->addChild(sprite);
	
	/*
      Here we create a button using one of rob's classes, CCMenuItemSpriteExtra
      (despite the name it's not in cocos2d), and to do this we use gd.h, which
      contains a bunch of useful functions.
      CCMenuItemSpriteExtra is the button you can click on and it does a bounce animation
    */
	
    auto button = CCMenuItemSpriteExtra::create(
        buttonSprite, // the sprite the button will use
		buttonSprite, // the sprite the button will use
		/*
          Here is the "target" for the callback function, most of the time it
          will be the current `this` (in our case self) and since callback
          functions have to be class methods, the target will be
          the `this` pointer in the method. It can be anything (except 0) but
          it's an useful way of using something in the callback.
        */
        self,
		/*
          Here is the callback that is called when you press the button. It's
          wrapped in a macro, which casts it to the correct type used by cocos.
          The callback is in CustomLayer because as previously mentioned, it has to
          be a class method, and we're not inside a class. I could just create a class
          specifically for this callback (say `Callback::switchToCustomLayer`), but i
          find that kinda messy and we can just use this class anyways.
        */
        menu_selector(CustomLayer::switchToCustomLayerButton)
    );
	
	// continue reading on `custom-layer.hpp`, where our CustomLayer is defined

    // All CCMenuItems need to be in a CCMenu to work,
    // otherwise you can't click on the button
	
    auto menu = CCMenu::create();
    menu->addChild(button);
	
	//the default position of CCMenu is the center of the screen, keep that in mind
    //when positioning your nodes. In this case we'll set the position to the bottom left
	
    menu->setPosition({150, 100});

    self->addChild(menu);

    return true;
}

//this is where all your hooks should be
void ApplyHooks() {
	/*
      Here we are hooking MenuLayer::init, by giving the symbol of the function
      and what function to hook it to, as well as a trampoline, which is used to call the
      original function without going through our hook.
      To give a basic explanation: hooking a function means overwriting its first few
      instructions, making it redirect code execution to our own function.
      Hooking the init function of a node (in this case a layer) is a common practice as
      that is where you should initialize the elements in the node, and in a hook, you
      can add your own nodes.
    
	
	 To make our hooks we will use the hooking.so shared library
	 to shorten the code I have made this HOOK macro that I think looks much better
	 If you want to take a look go to include/includes/hooking.h
	
		
	 To hook functions on android we specify the symbol of the function.
	 Symbols can be found easily by using a reverse engineering tool like IDA or Ghidra
	*/
	HOOK("_ZN9MenuLayer4initEv", MenuLayer_initH, MenuLayer_init);
}

//this is where your starting patches should be
void ApplyPatches() {
	
	//Let's see how we can use KittyMemory for runtime patching
	//We'll use the PatchManager class which is a wrapper for KittyMemory
	//include/includes/patch.h
	
	
	//As an example, let's remove the main play button in MenuLayer with a patch
	
	PatchManager tmp;
	
	//in this case, to remove a button we have to patch the closest BLX instruction after the button's creation
	//the play button gets created at 0x20CDC8 and we can see the closest BLX at 0x20CDD8
	//we change the BLX instruction to a NOP instruction
	//NOP means “No Operation” and does nothing during execution.
	//in our case, we need to use the thumb instruction set
	//the NOP instruction, converted to HEX and to the thumb instruction set is 00 BF
	//I recommend using the arm converter website, very helpful
	//https://armconverter.com/?code=NOP

	//name of the shared library we want to patch, adress, new bytes starting from that adress
	tmp.addPatch("libcocos2dcpp.so", 0x20CDD8, "00 BF");
	
	//make sure to apply the patches
	tmp.Modify();
}

//this function will run when the app starts
void loader() {
	ApplyHooks();
	ApplyPatches();
}

//starter
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	loader();
	return JNI_VERSION_1_6;
}   

