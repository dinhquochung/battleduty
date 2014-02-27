#include "AppDelegate.h"
#include "GameLayer.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
    
    CCSize screenSize = eglView->getFrameSize();
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(768, 1024,　kResolutionExactFit);
    //if device's screen width is greater than 768, use high definition images
    if (screenSize.width > 768) {
        CCFileUtils::sharedFileUtils()->addSearchPath("hd");
        director->setContentScaleFactor(2);
    } else {
        //or else, use standard definition
        CCFileUtils::sharedFileUtils()->addSearchPath("sd");
        director->setContentScaleFactor(1);
    }
	
    SimpleAudioEngine::sharedEngine()->preloadEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename("hit.wav").c_str());
    SimpleAudioEngine::sharedEngine()->preloadEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename("score.wav").c_str());
                                                                                                              
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = GameLayer::scene();
    
    // run
    director->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
