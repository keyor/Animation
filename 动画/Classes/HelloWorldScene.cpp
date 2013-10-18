#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    ///   步骤：  1 初始化精灵缓存加载plist文件   2创建精灵帧   3将精灵帧放到animation中4 然后封装animation成animate 5在 runAction 
    
    ///////type1类型1111111111111111111

    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* sprite=CCSprite::create("grossini_dance_01.png");
    
    addChild(sprite);
    sprite->setPosition(ccp(size.width/2,size.height/2));
    //动画帧， 放到CCAnimation中
    CCAnimation *animation=CCAnimation::create();///分配空间并初始化了 
    for (int i=1; i<15; i++) {
        CCString*fileName=CCString::createWithFormat("grossini_dance_%02d.png",i);
        //创建一个精灵帧
//        CCSize spriteSize=sprite->getContentSize();
//        CCRect rect=CCRect(0,0,spriteSize.width,spriteSize.height);
//        //做好一个精灵帧
//        CCSpriteFrame*frame=CCSpriteFrame::create(fileName->getCString(), rect);
//        ///将精灵帧加到animation中
//        animation->addSpriteFrame(frame);
        
        ////渲染每一帧动画 耗性能 一帧帧加载
        
        //一句话代替
        animation->addSpriteFrameWithFileName(fileName->getCString());
    } 
    animation->setDelayPerUnit(0.1f);
    animation->setLoops(-1);//-1表示一直执行
    ///将animation 封转成animate类
    CCAnimate *animate=CCAnimate::create(animation);
 
    sprite->runAction(animate);//执行这个动作
    
   
    
    
    ////////////type2 类型22222222222  纹理图  （rec）85*121 判断好起点
  
    
//    CCSize size=CCDirector::sharedDirector()->getWinSize();
//    CCSprite* sprite=CCSprite::create();
//     sprite->setPosition(ccp(size.width/2,size.height/2));
//    addChild(sprite);
//   
//    
//    CCAnimation *animation=CCAnimation::create();///创建一个animation容器
//    animation->setDelayPerUnit(0.1f);///设定时间间隔
//    animation->setLoops(-1);//-1表示一直执行
//    
//    
//    CCTextureCache* cache=CCTextureCache::sharedTextureCache();
//    CCTexture2D* texture=cache->addImage("grossini_dance_atlas_nomipmap.png");
//    for (int i=0; i<5; i++) {
//        
//    
//        CCRect rect=CCRect (85*i,0,85,121);
//        //用纹理创建精灵帧
////        CCSpriteFrame *frame=CCSpriteFrame::createWithTexture(texture, rect);
////        animation->addSpriteFrame(frame);
//        
//        //替换以上两句
//        animation->addSpriteFrameWithTexture(texture, rect);
//       
//
//    }
//    
//    CCAnimate *animate=CCAnimate::create(animation);
//    
//    sprite->runAction(animate);//执行这个动作
//
    
    ////////////////type33333333333333333333333333
    
//    CCSize size=CCDirector::sharedDirector()->getWinSize();
//      CCSprite* sprite=CCSprite::create();
//       sprite->setPosition(ccp(size.width/2,size.height/2));
//   addChild(sprite);
//    
//    
//     CCAnimation *animation=CCAnimation::create();///创建一个animation容器
//    
//    CCSpriteFrameCache*frameCache=CCSpriteFrameCache::sharedSpriteFrameCache();
//    frameCache->addSpriteFramesWithFile("grossini.plist");
// 
//    for (int i =1; i<15;i++) {
//        
//        CCString *fileName=CCString::createWithFormat("grossini_dance_%02d.png",i);///为什么是%02d??????
//        
//        CCSpriteFrame*frame=frameCache->spriteFrameByName(fileName->getCString());
//        animation->addSpriteFrame(frame);/
//        
//        
//        
//    }
//    
//    animation->setDelayPerUnit(0.1f);///设定时间间隔
//       animation->setLoops(-1);//-1表示一直执行
//    
//    CCAnimationCache*animationCache=CCAnimationCache::sharedAnimationCache();
//    animationCache->addAnimation(animation, "Z");
//    
//    CCAnimate*animate=CCAnimate::create(animationCache->animationByName("Z"));
//    //或者
////    CCAnimate*animate=CCAnimate::create(animation);
//   sprite-> runAction(animate);
//    
    
    
    
    
    
/////////////type444444444444444444444444444
    
    
//    CCSize size=CCDirector::sharedDirector()->getWinSize();
//    CCSprite* sprite=CCSprite::create();
//    sprite->setPosition(ccp(size.width/2,size.height/2));
//    addChild(sprite);
//    
//    
//    CCAnimation *animation1=CCAnimation::create();///创建一个
//    //图片加载到精灵缓存中
//    
//    CCSpriteFrameCache*spriteCache=CCSpriteFrameCache::sharedSpriteFrameCache();
//    
//    spriteCache->addSpriteFramesWithFile("grossini_blue.plist");
//    spriteCache->addSpriteFramesWithFile("grossini_gray.plist");
//    spriteCache->addSpriteFramesWithFile("grossini.plist");
//    
//    
//    
//    
//    
//    CCAnimationCache*animationCache=CCAnimationCache::sharedAnimationCache();
//    animationCache->addAnimationsWithFile("animations.plist");
//    
//    CCAnimation *animation=animationCache->animationByName("dance_1");
//    
//    CCAnimate* animate=CCAnimate::create(animation);
//    sprite->runAction(animate);
    return true;
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
