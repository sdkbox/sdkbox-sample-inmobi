
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginInMobi.setListener({
            bannerDidFinishLoading: function() {
                cc.log('bannerDidFinishLoading');
            },
            bannerDidFailToLoadWithError: function(code, description) {
                cc.log('bannerDidFailToLoadWithError code:' + code + ' desc:' + description);
            },
            bannerDidInteractWithParams: function(params) {
                cc.log('bannerDidInteractWithParams');
            },
            userWillLeaveApplicationFromBanner: function() {
                cc.log('userWillLeaveApplicationFromBanner');
            },
            bannerWillPresentScreen: function() {
                cc.log('bannerWillPresentScreen');
            },
            bannerDidPresentScreen: function() {
                cc.log('bannerDidPresentScreen');
            },
            bannerWillDismissScreen: function() {
                cc.log('bannerWillDismissScreen');
            },
            bannerDidDismissScreen: function() {
                cc.log('bannerDidDismissScreen');
            },
            bannerRewardActionCompletedWithRewards: function(rewards) {
                cc.log('bannerRewardActionCompletedWithRewards');
            },
            interstitialDidFinishLoading: function() {
                cc.log('interstitialDidFinishLoading');
            },
            interstitialDidFailToLoadWithError: function(code, description) {
                cc.log('interstitialDidFailToLoadWithError code:' + code + ' desc:' + description);
            },
            interstitialWillPresent: function() {
                cc.log('interstitialWillPresent');
            },
            interstitialDidPresent: function() {
                cc.log('interstitialDidPresent');
            },
            interstitialDidFailToPresentWithError: function(code, description) {
                cc.log('interstitialDidFailToPresentWithError code:' + code + ' desc:' + description);
            },
            interstitialWillDismiss: function() {
                cc.log('interstitialWillDismiss');
            },
            interstitialDidDismiss: function() {
                cc.log('interstitialDidDismiss');
            },
            interstitialDidInteractWithParams: function(params) {
                cc.log('interstitialDidInteractWithParams');
            },
            interstitialRewardActionCompletedWithRewards: function(rewards) {
                cc.log('interstitialRewardActionCompletedWithRewards');
            },
            userWillLeaveApplicationFromInterstitial: function() {
                cc.log('userWillLeaveApplicationFromInterstitial');
            }
        });
        sdkbox.PluginInMobi.init();

        // base setting
        var ver = sdkbox.PluginInMobi.getVersion();
        cc.log("inmobi plugin version: " + ver.toString());

        sdkbox.PluginInMobi.setLogLevel(sdkbox.PluginInMobi.SBIMSDKLogLevel.kIMSDKLogLevelDebug);
        sdkbox.PluginInMobi.addIdForType("test", sdkbox.PluginInMobi.SBIMSDKIdType.kIMSDKIdTypeLogin);
        sdkbox.PluginInMobi.removeIdType(sdkbox.PluginInMobi.SBIMSDKIdType.kIMSDKIdTypeLogin);
        sdkbox.PluginInMobi.setAge(18);
        sdkbox.PluginInMobi.setAreaCode("area code");
        sdkbox.PluginInMobi.setAgeGroup(sdkbox.PluginInMobi.SBIMSDKAgeGroup.kIMSDKAgeGroupBetween18And20);
        sdkbox.PluginInMobi.setYearOfBirth(1989);
        sdkbox.PluginInMobi.setEducation(sdkbox.PluginInMobi.SBIMSDKEducation.kIMSDKEducationHighSchoolOrLess);
        sdkbox.PluginInMobi.setEthnicity(sdkbox.PluginInMobi.SBIMSDKEthnicity.kIMSDKEthnicityHispanic);
        sdkbox.PluginInMobi.setGender(sdkbox.PluginInMobi.SBIMSDKGender.kIMSDKGenderMale);
        sdkbox.PluginInMobi.setHouseholdIncome(sdkbox.PluginInMobi.SBIMSDKHouseholdIncome.kIMSDKHouseholdIncomeBelow5kUSD);
        sdkbox.PluginInMobi.setIncome(4500);
        sdkbox.PluginInMobi.setInterests("game");
        sdkbox.PluginInMobi.setLanguage("zh-cn");
        sdkbox.PluginInMobi.setLocation("cd", "sc", "usa");
        sdkbox.PluginInMobi.setLocation(102, 348);
        sdkbox.PluginInMobi.setNationality("nationality");
        sdkbox.PluginInMobi.setPostalCode("618000");

        // interstitail setting
        sdkbox.PluginInMobi.disableHardwareAccelerationForInterstitial();
        sdkbox.PluginInMobi.setInterstitialKeywords("spoort");

        // banner setting
        sdkbox.PluginInMobi.disableHardwareAccelerationForBanner();
        sdkbox.PluginInMobi.setBannerAnimationType(sdkbox.PluginInMobi.SBIMBannerAnimationType.kIMBannerAnimationTypeRotateHorizontalAxis);
        sdkbox.PluginInMobi.setBannerKeywords("music");

        sdkbox.PluginInMobi.shouldAutoRefresh(true);
        sdkbox.PluginInMobi.setRefreshInterval(60);


        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("Load Interstitial", "sans", 28), function() {
            cc.log("Load Interstitial");
            if (sdkbox.PluginInMobi.isInterstitialReady()) {
                cc.log("Plugin InMobi interstitial ad is ready");
                sdkbox.PluginInMobi.showInterstitial();
            } else {
                cc.log("Plugin InMobi interstitial ad is not ready");
            }
        });

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("Show Interstitial", "sans", 28), function() {
            cc.log("Show Interstitial");
            sdkbox.PluginInMobi.loadInterstitial();
        });

        var item3 = new cc.MenuItemLabel(new cc.LabelTTF("Show Banner", "sans", 28), function() {
            cc.log("Show Banner");
            sdkbox.PluginInMobi.loadBanner();
        });

        var winsize = cc.winSize;
        var menu = new cc.Menu(item1, item2, item3);
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

