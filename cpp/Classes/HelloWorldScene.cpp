
#include "HelloWorldScene.h"
#include "PluginInMobi/PluginInMobi.h"

USING_NS_CC;

class IMListener : public sdkbox::InMobiListener {
public:
    void bannerDidFinishLoading() {
        CCLOG("bannerDidFinishLoading");
    };
    void bannerDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        CCLOG("bannerDidFailToLoadWithError status:%d, desc:%s", code, description.c_str());
    };

    void bannerDidInteractWithParams(const std::map<std::string, std::string>& params) {
        CCLOG("bannerDidInteractWithParams");
    };

    void userWillLeaveApplicationFromBanner() {
        CCLOG("userWillLeaveApplicationFromBanner");
    };

    void bannerWillPresentScreen() {
        CCLOG("bannerWillPresentScreen");
    };

    void bannerDidPresentScreen() {
        CCLOG("bannerDidPresentScreen");
    };

    void bannerWillDismissScreen() {
        CCLOG("bannerWillDismissScreen");
    };

    void bannerDidDismissScreen() {
        CCLOG("bannerDidDismissScreen");
    };

    void bannerRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        CCLOG("bannerRewardActionCompletedWithRewards");
    };

    void interstitialDidFinishLoading() {
        CCLOG("interstitialDidFinishLoading");
    };

    void interstitialDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        CCLOG("interstitialDidFailToLoadWithError status:%d, desc:%s", code, description.c_str());
    };

    void interstitialWillPresent() {
        CCLOG("interstitialWillPresent");
    };

    void interstitialDidPresent() {
        CCLOG("interstitialDidPresent");
    };

    void interstitialDidFailToPresentWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        CCLOG("interstitialDidFailToPresentWithError");
    };

    void interstitialWillDismiss() {
        CCLOG("interstitialWillDismiss");
    };

    void interstitialDidDismiss() {
        CCLOG("interstitialDidDismiss");
    };

    void interstitialDidInteractWithParams(const std::map<std::string, std::string>& params) {
        CCLOG("interstitialDidInteractWithParams");
    };

    void interstitialRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        CCLOG("interstitialRewardActionCompletedWithRewards");
    };

    void userWillLeaveApplicationFromInterstitial() {
        CCLOG("userWillLeaveApplicationFromInterstitial");
    };
};


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

    CCLOG("Sample Startup");

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
    auto ver = sdkbox::PluginInMobi::getVersion();
    CCLOG("inmobi plugin version:%s", ver.c_str());
    sdkbox::PluginInMobi::setLogLevel(sdkbox::PluginInMobi::SBIMSDKLogLevel::kIMSDKLogLevelDebug);
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
    sdkbox::PluginInMobi::disableHardwareAccelerationForInterstitial();
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

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Load Interstitial", "sans", 24), [](Ref*){
        CCLOG("Load Interstitial");
        if (sdkbox::PluginInMobi::isInterstitialReady()) {
            CCLOG("Plugin InMobi interstitial ad is ready");
            sdkbox::PluginInMobi::showInterstitial();
        } else {
            CCLOG("Plugin InMobi interstitial ad is not ready");
        }
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Interstitial", "sans", 24), [](Ref*){
        CCLOG("Show Interstitial");
        sdkbox::PluginInMobi::loadInterstitial();
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Banner", "sans", 24), [](Ref*){
        CCLOG("Show Banner");
        sdkbox::PluginInMobi::loadBanner();
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

