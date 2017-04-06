
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginInMobi:setListener(function(args)
        dump(args)
    end)
    sdkbox.PluginInMobi:init()

    -- base setting
    local ver = sdkbox.PluginInMobi:getVersion()
    printf("inmobi plugin version:%s", ver)

    sdkbox.PluginInMobi:setLogLevel(sdkbox.PluginInMobi.SBIMSDKLogLevel.kIMSDKLogLevelDebug)
    sdkbox.PluginInMobi:addIdForType("test", sdkbox.PluginInMobi.SBIMSDKIdType.kIMSDKIdTypeLogin)
    sdkbox.PluginInMobi:removeIdType(sdkbox.PluginInMobi.SBIMSDKIdType.kIMSDKIdTypeLogin)
    sdkbox.PluginInMobi:setAge(18)
    sdkbox.PluginInMobi:setAreaCode("area code")
    sdkbox.PluginInMobi:setAgeGroup(sdkbox.PluginInMobi.SBIMSDKAgeGroup.kIMSDKAgeGroupBetween18And20)
    sdkbox.PluginInMobi:setYearOfBirth(1989)
    sdkbox.PluginInMobi:setEducation(sdkbox.PluginInMobi.SBIMSDKEducation.kIMSDKEducationHighSchoolOrLess)
    sdkbox.PluginInMobi:setEthnicity(sdkbox.PluginInMobi.SBIMSDKEthnicity.kIMSDKEthnicityHispanic)
    sdkbox.PluginInMobi:setGender(sdkbox.PluginInMobi.SBIMSDKGender.kIMSDKGenderMale)
    sdkbox.PluginInMobi:setHouseholdIncome(sdkbox.PluginInMobi.SBIMSDKHouseholdIncome.kIMSDKHouseholdIncomeBelow5kUSD)
    sdkbox.PluginInMobi:setIncome(4500)
    sdkbox.PluginInMobi:setInterests("game")
    sdkbox.PluginInMobi:setLanguage("zh-cn")
    sdkbox.PluginInMobi:setLocation("cd", "sc", "usa")
    sdkbox.PluginInMobi:setLocation(102, 348)
    sdkbox.PluginInMobi:setNationality("nationality")
    sdkbox.PluginInMobi:setPostalCode("618000")

    -- interstitail setting
    sdkbox.PluginInMobi:disableHardwareAccelerationForInterstitial()
    sdkbox.PluginInMobi:setInterstitialKeywords("spoort")

    -- banner setting
    sdkbox.PluginInMobi:disableHardwareAccelerationForBanner()
    sdkbox.PluginInMobi:setBannerAnimationType(sdkbox.PluginInMobi.SBIMBannerAnimationType.kIMBannerAnimationTypeRotateHorizontalAxis)
    sdkbox.PluginInMobi:setBannerKeywords("music")

    sdkbox.PluginInMobi:shouldAutoRefresh(true)
    sdkbox.PluginInMobi:setRefreshInterval(60)

    local item1 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Load Interstitial (ad2)", "sans", 28))
    item1:onClicked(function()
        if sdkbox.PluginInMobi:isInterstitialReady("ad3") then
            print("Load Plugin InMobi interstitial (ad2)")
        else
            sdkbox.PluginInMobi:loadInterstitial("ad2")
            print("Plugin InMobi interstitial (ad2) is not ready")
        end
    end)

    local item2 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Show Interstitial (ad2)", "sans", 28))
    item2:onClicked(function()
        print("Show Interstitial (ad2)")
        sdkbox.PluginInMobi:showInterstitial("ad2")
    end)


    local item3 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Load Interstitial (ad3)", "sans", 28))
    item3:onClicked(function()
        if sdkbox.PluginInMobi:isInterstitialReady("ad3") then
            print("Load Plugin InMobi interstitial (ad3)")
        else
            sdkbox.PluginInMobi:loadInterstitial("ad3")
            print("Plugin InMobi interstitial (ad3) is not ready")
        end
    end)

    local item4 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Show Interstitial (ad3)", "sans", 28))
    item4:onClicked(function()
        print("Show Interstitial (ad3)")
        sdkbox.PluginInMobi:showInterstitial("ad3")
    end)

    local item5 = cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Show Banner", "sans", 28))
    item5:onClicked(function()
        print("Show Banner")
        sdkbox.PluginInMobi:loadBanner()
    end)

    local menu = cc.Menu:create(item1, item2, item3, item4, item5)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
