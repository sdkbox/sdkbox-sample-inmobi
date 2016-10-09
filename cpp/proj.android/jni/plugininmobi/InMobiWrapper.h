/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_INMOBI_WRAPPER_H_
#define _PLUGIN_INMOBI_WRAPPER_H_

#include "PluginInMobi.h"
#include "json98.h"

#define TAG "InMobi"
#define VERSION "5.3.0"

namespace sdkbox {

class InMobiWrapper {
public:
    struct ad_info {
        std::string name;
        std::string ID;
        std::string type;
        std::string alignment;
        int with;
        int height;
    };

public:

    static InMobiWrapper* getInstance();

    virtual bool init() = 0;
    virtual bool __init( bool asAdUnit ) = 0;
    virtual void setListener(InMobiListener* listener) = 0;
    virtual InMobiListener* getListener() = 0;
    virtual void removeListener() = 0;
    virtual void initWithAccountID(const std::string& accountID) = 0;
    virtual std::string getVersion() = 0;
    virtual void setLogLevel(PluginInMobi::SBIMSDKLogLevel desiredLogLevel) = 0;
    virtual void addIdForType(const std::string& identifier, PluginInMobi::SBIMSDKIdType type) = 0;
    virtual void removeIdType(PluginInMobi::SBIMSDKIdType type) = 0;
    virtual void setAge(unsigned short age) = 0;
    virtual void setAreaCode(const std::string& areaCode) = 0;
    virtual void setAgeGroup(PluginInMobi::SBIMSDKAgeGroup ageGroup) = 0;
    virtual void setYearOfBirth(int yearOfBirth) = 0;
    virtual void setEducation(PluginInMobi::SBIMSDKEducation education) = 0;
    virtual void setEthnicity(PluginInMobi::SBIMSDKEthnicity ethnicity) = 0;
    virtual void setGender(PluginInMobi::SBIMSDKGender gender) = 0;
    virtual void setHouseholdIncome(PluginInMobi::SBIMSDKHouseholdIncome income) = 0;
    virtual void setIncome(unsigned int income) = 0;
    virtual void setInterests(const std::string& interests) = 0;
    virtual void setLanguage(const std::string& language) = 0;
    virtual void setLocation(const std::string& city, const std::string& state, const std::string& country) = 0;
    virtual void setLocation(double latitude, double longitude) = 0;
    virtual void setNationality(const std::string& nationality) = 0;
    virtual void setPostalCode(const std::string& postalcode) = 0;
    virtual void shouldAutoRefresh(bool refresh) = 0;
    virtual void setRefreshInterval(int interval) = 0;
    virtual void setPlacementId(long long placementId) = 0;
    virtual void loadBanner() = 0;
    virtual void disableHardwareAccelerationForBanner() = 0;
    virtual void setBannerAnimationType(PluginInMobi::SBIMBannerAnimationType animationType) = 0;
    virtual void setBannerExtras(const std::map<std::string, std::string>& extras) = 0;
    virtual void setBannerKeywords(const std::string& keywords) = 0;
    virtual void hideBanner() = 0;
    virtual void loadInterstitial() = 0;
    virtual bool isInterstitialReady() = 0;
    virtual void showInterstitial() = 0;
    virtual void showInterstitial(PluginInMobi::SBIMInterstitialAnimationType type) = 0;
    virtual void showInterstitial(int enterAnimationResourcedId, int exitAnimationResourceId) = 0;
    virtual void disableHardwareAccelerationForInterstitial() = 0;
    virtual void setInterstitialExtras(const std::map<std::string, std::string>& extras) = 0;
    virtual void setInterstitialKeywords(const std::string& keywords) = 0;
    virtual std::map<std::string, std::string> addCocosInfoIntoExtras(const std::map<std::string, std::string>& extras) = 0;
};

    class InMobiWrapperEnabled : public InMobiWrapper {
    public:
        InMobiWrapperEnabled();

        bool init();
        bool __init( bool asAdUnit );
        void setListener(InMobiListener* listener);
        InMobiListener* getListener();
        void removeListener();

        void initWithAccountID(const std::string& accountID);
        std::string getVersion();
        void setLogLevel(PluginInMobi::SBIMSDKLogLevel desiredLogLevel);
        void addIdForType(const std::string& identifier, PluginInMobi::SBIMSDKIdType type);
        void removeIdType(PluginInMobi::SBIMSDKIdType type);
        void setAge(unsigned short age);
        void setAreaCode(const std::string& areaCode);
        void setAgeGroup(PluginInMobi::SBIMSDKAgeGroup ageGroup);
        void setYearOfBirth(int yearOfBirth);
        void setEducation(PluginInMobi::SBIMSDKEducation education);
        void setEthnicity(PluginInMobi::SBIMSDKEthnicity ethnicity);
        void setGender(PluginInMobi::SBIMSDKGender gender);
        void setHouseholdIncome(PluginInMobi::SBIMSDKHouseholdIncome income);
        void setIncome(unsigned int income);
        void setInterests(const std::string& interests);
        void setLanguage(const std::string& language);
        void setLocation(const std::string& city, const std::string& state, const std::string& country);
        void setLocation(double latitude, double longitude);
        void setNationality(const std::string& nationality);
        void setPostalCode(const std::string& postalcode);

        void shouldAutoRefresh(bool refresh);
        void setRefreshInterval(int interval);
        void setPlacementId(long long placementId);
        void loadBanner();

        void disableHardwareAccelerationForBanner();
        void setBannerAnimationType(PluginInMobi::SBIMBannerAnimationType animationType);
        void setBannerExtras(const std::map<std::string, std::string>& extras);
        void setBannerKeywords(const std::string& keywords);
        void hideBanner();

        void loadInterstitial();
        bool isInterstitialReady();
        void showInterstitial();
        void showInterstitial(PluginInMobi::SBIMInterstitialAnimationType type);
        void showInterstitial(int enterAnimationResourcedId, int exitAnimationResourceId);

        void disableHardwareAccelerationForInterstitial();
        void setInterstitialExtras(const std::map<std::string, std::string>& extras);
        void setInterstitialKeywords(const std::string& keywords);

        std::map<std::string, std::string> addCocosInfoIntoExtras(const std::map<std::string, std::string>& extras);
    protected:
        bool nativeInit(const Json& config, bool asAdUnit);
        std::string nativeSDKVersion();


        InMobiListener* _listener;
        std::string _accountID;
        ad_info _banner;
        ad_info _interstitial;
    };

    class InMobiWrapperDisabled : public InMobiWrapper {
    public:

        bool init() { return false; }
        bool __init( bool asAdUnit ) {return false;}
        void setListener(InMobiListener* listener) {}
        InMobiListener* getListener() { return NULL;}
        void removeListener() {}

        void initWithAccountID(const std::string& accountID) {}
        std::string getVersion() { return ""; }
        void setLogLevel(PluginInMobi::SBIMSDKLogLevel desiredLogLevel) {}
        void addIdForType(const std::string& identifier, PluginInMobi::SBIMSDKIdType type) {}
        void removeIdType(PluginInMobi::SBIMSDKIdType type) {}
        void setAge(unsigned short age) {}
        void setAreaCode(const std::string& areaCode) {}
        void setAgeGroup(PluginInMobi::SBIMSDKAgeGroup ageGroup) {}
        void setYearOfBirth(int yearOfBirth) {}
        void setEducation(PluginInMobi::SBIMSDKEducation education) {}
        void setEthnicity(PluginInMobi::SBIMSDKEthnicity ethnicity) {}
        void setGender(PluginInMobi::SBIMSDKGender gender) {}
        void setHouseholdIncome(PluginInMobi::SBIMSDKHouseholdIncome income) {}
        void setIncome(unsigned int income) {}
        void setInterests(const std::string& interests) {}
        void setLanguage(const std::string& language) {}
        void setLocation(const std::string& city, const std::string& state, const std::string& country) {}
        void setLocation(double latitude, double longitude) {}
        void setNationality(const std::string& nationality) {}
        void setPostalCode(const std::string& postalcode) {}

        void shouldAutoRefresh(bool refresh) {}
        void setRefreshInterval(int interval) {}
        void setPlacementId(long long placementId) {}
        void loadBanner() {}

        void disableHardwareAccelerationForBanner() {}
        void setBannerAnimationType(PluginInMobi::SBIMBannerAnimationType animationType) {}
        void setBannerExtras(const std::map<std::string, std::string>& extras) {}
        void setBannerKeywords(const std::string& keywords) {}
        void hideBanner() {};

        void loadInterstitial() {}
        bool isInterstitialReady() { return false; }
        void showInterstitial() {}
        void showInterstitial(PluginInMobi::SBIMInterstitialAnimationType type) {}
        void showInterstitial(int enterAnimationResourcedId, int exitAnimationResourceId) {}

        void disableHardwareAccelerationForInterstitial() {}
        void setInterstitialExtras(const std::map<std::string, std::string>& extras) {}
        void setInterstitialKeywords(const std::string& keywords) {}

        std::map<std::string, std::string> addCocosInfoIntoExtras(const std::map<std::string, std::string>& extras) { return std::map<std::string,std::string>(); }

    };

}

#endif
