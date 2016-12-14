
#include "HelloWorldScene.h"
#include "PluginInMobi/PluginInMobi.h"

USING_NS_CC;

#include <vector>
#include <string>
using namespace std;

/******************
 * Show logs
 ******************/
std::vector<std::string> msgbuf;
static void showMsg(const std::string& msg) {
    //
    Label *label = dynamic_cast<Label*>(Director::getInstance()->getNotificationNode());
    if (label == nullptr) {
        auto size = Director::getInstance()->getWinSize();
        label = Label::createWithSystemFont("test", "arial", 16);
        label->setAnchorPoint(Vec2(0,0));
        label->setTextColor(Color4B(0, 255, 0, 255));
        label->setPosition(10, size.height*0.1);
        Director::getInstance()->setNotificationNode(label);
    }
    
    msgbuf.push_back(msg);
    if (msgbuf.size() > 10) {
        msgbuf.erase(msgbuf.cbegin());
    }
    
    
    std::string text = "";
    for (int i = 0; i < msgbuf.size(); i++) {
        stringstream buf;
        buf << i << " " << msgbuf[i] << "\n";
        text = text + buf.str();
    }
    
    label->setString(text);
}

/******************
 * InMobi Listener
 ******************/

class IMListener : public sdkbox::InMobiListener {
public:
    void bannerDidFinishLoading() {
        showMsg("bannerDidFinishLoading");
    };
    void bannerDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        showMsg("bannerDidFailToLoadWithError");
        CCLOG("bannerDidFailToLoadWithError status:%d, desc:%s", code, description.c_str());
    };

    void bannerDidInteractWithParams(const std::map<std::string, std::string>& params) {
        showMsg("bannerDidInteractWithParams");
    };

    void userWillLeaveApplicationFromBanner() {
        showMsg("userWillLeaveApplicationFromBanner");
    };

    void bannerWillPresentScreen() {
        showMsg("bannerWillPresentScreen");
    };

    void bannerDidPresentScreen() {
        showMsg("bannerDidPresentScreen");
    };

    void bannerWillDismissScreen() {
        showMsg("bannerWillDismissScreen");
    };

    void bannerDidDismissScreen() {
        showMsg("bannerDidDismissScreen");
    };

    void bannerRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        showMsg("bannerRewardActionCompletedWithRewards");
    };

    void interstitialDidFinishLoading() {
        showMsg("interstitialDidFinishLoading");
    };

    void interstitialDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        showMsg("interstitialDidFailToLoadWithError");
        CCLOG("interstitialDidFailToLoadWithError status:%d, desc:%s", code, description.c_str());
    };

    void interstitialWillPresent() {
        showMsg("interstitialWillPresent");
    };

    void interstitialDidPresent() {
        showMsg("interstitialDidPresent");
    };

    void interstitialDidFailToPresentWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        showMsg("interstitialDidFailToPresentWithError");
    };

    void interstitialWillDismiss() {
        showMsg("interstitialWillDismiss");
    };

    void interstitialDidDismiss() {
        showMsg("interstitialDidDismiss");
    };

    void interstitialDidInteractWithParams(const std::map<std::string, std::string>& params) {
        showMsg("interstitialDidInteractWithParams");
    };

    void interstitialRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        showMsg("interstitialRewardActionCompletedWithRewards");
    };

    void userWillLeaveApplicationFromInterstitial() {
        showMsg("userWillLeaveApplicationFromInterstitial");
    };
};

/******************
 * InMobi sample
 ******************/
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }

    showMsg("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginInMobi::setListener(new IMListener());
    sdkbox::PluginInMobi::init();

    //base setting
    string ver_str = "inmobi plugin version:";
    ver_str += sdkbox::PluginInMobi::getVersion();
    showMsg(ver_str);
    
    sdkbox::PluginInMobi::setLogLevel(sdkbox::PluginInMobi::SBIMSDKLogLevel::kIMSDKLogLevelDebug);

    testDemograpicFunctions();

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Load Interstitial", "arial", 24), [](Ref*){
        showMsg("Load Interstitial");
        sdkbox::PluginInMobi::loadInterstitial();
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Interstitial", "arial", 24), [](Ref*){
        
        if (sdkbox::PluginInMobi::isInterstitialReady())
        {
            showMsg("Plugin InMobi interstitial ad is ready");
            sdkbox::PluginInMobi::showInterstitial();
        }
        else
        {
            showMsg("Plugin InMobi interstitial ad is not ready");
        }
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Banner", "arial", 24), [](Ref*){
        showMsg("Show Banner");
        sdkbox::PluginInMobi::loadBanner();
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::testDemograpicFunctions()
{
    sdkbox::PluginInMobi::addIdForType("test", sdkbox::PluginInMobi::SBIMSDKIdType::kIMSDKIdTypeLogin);
    sdkbox::PluginInMobi::removeIdType(sdkbox::PluginInMobi::SBIMSDKIdType::kIMSDKIdTypeLogin);
    sdkbox::PluginInMobi::setAge(18);
    sdkbox::PluginInMobi::setAreaCode("area code");
    sdkbox::PluginInMobi::setAgeGroup(sdkbox::PluginInMobi::SBIMSDKAgeGroup::kIMSDKAgeGroupBetween18And20);
    sdkbox::PluginInMobi::setYearOfBirth(1989);
    sdkbox::PluginInMobi::setEducation(sdkbox::PluginInMobi::SBIMSDKEducation::kIMSDKEducationHighSchoolOrLess);
    sdkbox::PluginInMobi::setEthnicity(sdkbox::PluginInMobi::SBIMSDKEthnicity::kIMSDKEthnicityHispanic);
    sdkbox::PluginInMobi::setGender(sdkbox::PluginInMobi::SBIMSDKGender::kIMSDKGenderMale);
    sdkbox::PluginInMobi::setHouseholdIncome(sdkbox::PluginInMobi::SBIMSDKHouseholdIncome::kIMSDKHouseholdIncomeBelow5kUSD);
    sdkbox::PluginInMobi::setIncome(4500);
    sdkbox::PluginInMobi::setInterests("game");
    sdkbox::PluginInMobi::setLanguage("zh-cn");
    sdkbox::PluginInMobi::setLocation("cd", "sc", "usa");
    sdkbox::PluginInMobi::setLocation(102, 348);
    sdkbox::PluginInMobi::setNationality("nationality");
    sdkbox::PluginInMobi::setPostalCode("618000");
    
    //interstitail setting
    std::map<std::string, std::string> map;
    map.insert(std::make_pair("k1", "v1"));
    sdkbox::PluginInMobi::setInterstitialExtras(map);
    sdkbox::PluginInMobi::setInterstitialKeywords("spoort");
    
    //banner setting
    sdkbox::PluginInMobi::disableHardwareAccelerationForBanner();
    sdkbox::PluginInMobi::setBannerAnimationType(sdkbox::PluginInMobi::SBIMBannerAnimationType::kIMBannerAnimationTypeRotateHorizontalAxis);
    sdkbox::PluginInMobi::setBannerExtras(map);
    sdkbox::PluginInMobi::setBannerKeywords("music");
    
    sdkbox::PluginInMobi::shouldAutoRefresh(true);
    sdkbox::PluginInMobi::setRefreshInterval(60);
}

