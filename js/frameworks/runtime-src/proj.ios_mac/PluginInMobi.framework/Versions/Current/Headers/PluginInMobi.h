/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_INMOBI_H_
#define _PLUGIN_INMOBI_H_

#include <string>
#include <map>

namespace sdkbox {

    class InMobiListener;
    class PluginInMobi {
    public:

        enum SBIMStatusCode {
            kIMStatusCodeNetworkUnReachable,
            kIMStatusCodeNoFill,
            kIMStatusCodeRequestInvalid,
            kIMStatusCodeRequestPending,
            kIMStatusCodeRequestTimedOut,
            kIMStatusCodeInternalError,
            kIMStatusCodeServerError,
            kIMStatusCodeAdActive,
            kIMStatusCodeEarlyRefreshRequest
        };

        enum SBIMSDKIdType {
            kIMSDKIdTypeSession,
            kIMSDKIdTypeLogin
        };

        enum SBIMSDKLogLevel {
            kIMSDKLogLevelNone,
            kIMSDKLogLevelError,
            kIMSDKLogLevelDebug
        };

        enum SBIMSDKGender {
            kIMSDKGenderMale = 1,
            kIMSDKGenderFemale
        };

        enum SBIMSDKEducation {
            kIMSDKEducationHighSchoolOrLess = 1,
            kIMSDKEducationCollegeOrGraduate,
            kIMSDKEducationPostGraduateOrAbove
        };

        enum SBIMSDKEthnicity {
            kIMSDKEthnicityHispanic = 1,
            kIMSDKEthnicityCaucasian,
            kIMSDKEthnicityAsian,
            kIMSDKEthnicityAfricanAmerican,
            kIMSDKEthnicityOther
        };

        enum SBIMSDKHouseholdIncome {
            kIMSDKHouseholdIncomeBelow5kUSD = 1,
            kIMSDKHouseholdIncomeBetweek5kAnd10kUSD,
            kIMSDKHouseholdIncomeBetween10kAnd15kUSD,
            kIMSDKHouseholdIncomeBetween15kAnd20kUSD,
            kIMSDKHouseholdIncomeBetween20kAnd25kUSD,
            kIMSDKHouseholdIncomeBetween25kAnd50kUSD,
            kIMSDKHouseholdIncomeBetween50kAnd75kUSD,
            kIMSDKHouseholdIncomeBetween75kAnd100kUSD,
            kIMSDKHouseholdIncomeBetween100kAnd150kUSD,
            kIMSDKHouseholdIncomeAbove150kUSD
        };

        enum SBIMSDKAgeGroup {
            kIMSDKAgeGroupBelow18 = 1,
            kIMSDKAgeGroupBetween18And20,
            kIMSDKAgeGroupBetween21And24,
            kIMSDKAgeGroupBetween25And34,
            kIMSDKAgeGroupBetween35And54,
            kIMSDKAgeGroupAbove55
        };

        enum SBIMInterstitialAnimationType {
            kIMInterstitialAnimationTypeCoverVertical,
            kIMInterstitialAnimationTypeFlipHorizontal,
            kIMInterstitialAnimationTypeNone
        };

        enum SBIMBannerAnimationType {
            kIMBannerAnimationTypeOff,
            kIMBannerAnimationTypeAlpha,
            kIMBannerAnimationTypeRotateHorizontalAxis,
            kIMBannerAnimationTypeRotateVerticalAxis
        };

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for inmobi events
         */
        static void setListener(InMobiListener* listener);

        /**
         * Get the listener
         */
        static InMobiListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Use this to get the version of the SDK.
         * @return The version of the SDK.
         */
        static std::string getVersion();

        /**
         * Set the log level for SDK's logs
         * @param desiredLogLevel The desired level of logs.
         */
        static void setLogLevel(SBIMSDKLogLevel desiredLogLevel);
        /**
         * Register a user specific id with the SDK
         * @param identifier The user Id.
         * @param type The user Id type.
         */
        static void addIdForType(const std::string& identifier, SBIMSDKIdType type);
        /**
         * Deregister a particular set of Ids
         * @param type The user Id type.
         */
        static void removeIdType(SBIMSDKIdType type);
        /**
         * Provide the user's age to the SDK for targetting purposes.
         * @param age The user's age.
         */
        static void setAge(int age);
        /**
         * Provide the user's area code to the SDK for targetting purposes.
         * @param areaCode The user's area code.
         */
        static void setAreaCode(const std::string& areaCode);
        /**
         * Provide the user's age group to the SDK for targetting purposes.
         * @param ageGroup The user's age group.
         */
        static void setAgeGroup(SBIMSDKAgeGroup ageGroup);
        /**
         * Provide a user's date of birth to the SDK for targetting purposes.
         * @param dateOfBirth The user's date of birth.
         */
        static void setYearOfBirth(int yearOfBirth);
        /**
         * Provide the user's education status to the SDK for targetting purposes.
         * @param education The user's education status.
         */
        static void setEducation(SBIMSDKEducation education);
        /**
         * Provide the user's ethnicity to the SDK for targetting purposes.
         * @param ethnicity The user's ethnicity.
         */
        static void setEthnicity(SBIMSDKEthnicity ethnicity);
        /**
         * Provide the user's gender to the SDK for targetting purposes.
         * @param gender The user's gender.
         */
        static void setGender(SBIMSDKGender gender);
        /**
         * Provide the user's household income to the SDK for targetting purposes.
         * @param income The user's household income.
         */
        static void setHouseholdIncome(SBIMSDKHouseholdIncome income);
        /**
         * Provide the user's income to the SDK for targetting purposes.
         * @param income The user's income.
         */
        static void setIncome(unsigned int income);
        /**
         * Provide the user's interests to the SDK for targetting purposes.
         * @param interests The user's interests.
         */
        static void setInterests(const std::string& interests);
        /**
         * Provide the user's preferred language to the SDK for targetting purposes.
         * @param language The user's language.
         */
        static void setLanguage(const std::string& language);
        /**
         * Provide the user's location to the SDK for targetting purposes.
         * @param city The user's city.
         * @param state The user's state.
         * @param country The user's country.
         */
        static void setLocation(const std::string& city, const std::string& state, const std::string& country);

        /**
         * Provide the user's location to the SDK for targetting purposes.
         * @param location: The location of the user
         */
        static void setLocation(double latitude, double longitude);
        /**
         * Provide the user's nationality to the SDK for targetting purposes.
         * @param nationality The user's nationality.
         */
        static void setNationality(const std::string& nationality);
        /**
         * Provide the user's postal code to the SDK for targetting purposes.
         * @param postalcode The user's postalcode.
         */
        static void setPostalCode(const std::string& postalcode);


        /**
         * Control if the banner should auto-refresh ad content.
         */
        static void shouldAutoRefresh(bool refresh);
        /**
         * Specify the refresh interval for the banner ad.
         */
        static void setRefreshInterval(int interval);
        /**
         * Submit a request to load banner ad content.
         */
        static void loadBanner();

        /**
         * Turn off hardware acceleration on the underlying views.
         * vaild on android
         */
        static void disableHardwareAccelerationForBanner();
        /**
         * Set the animation preference on the banner views during ad refresh.
         */
        static void setBannerAnimationType(SBIMBannerAnimationType animationType);
        /**
         * Set any additional custom parameters that will be sent in the ad request.
         */
        static void setBannerExtras(const std::map<std::string, std::string>& extras);
        /**
         * Set comma delimited keywords for targeting purpose
         */
        static void setBannerKeywords(const std::string& keywords);


        /**
         * Submit a request to load interstitial ad content.
         */
        static void loadInterstitial();
        /**
         * Returns true if the interstitial was loaded successfully and in ready to be shown.
         */
        static bool isInterstitialReady();
        /**
         * Displays the interstitial on the screen
         */
        static void showInterstitial();
        /**
         * Displays the interstitial on the screen
         * valid on ios
         */
        static void showInterstitial(SBIMInterstitialAnimationType type);

        /**
         * Displays the interstitial on the screen
         * valid on android
         */
        static void showInterstitial(int enterAnimationResourcedId, int exitAnimationResourceId);
        /**
         * Disable hardware acceleration on the underlying views.
         * valid on android
         */
        static void disableHardwareAccelerationForInterstitial();
        /**
         * Set any additional custom parameters that will be sent in the ad request.
         */
        static void setInterstitialExtras(const std::map<std::string, std::string>& extras);
        /**
         * Set comma delimited keywords for targeting purpose
         */
        static void setInterstitialKeywords(const std::string& keywords);

        };

    class InMobiListener {
    public:

        /**
         * Notifies the delegate that the banner has finished loading
         */
        virtual void bannerDidFinishLoading() {};
        /**
         * Notifies the delegate that the banner has failed to load with some error.
         */
        virtual void bannerDidFailToLoadWithError(PluginInMobi::SBIMStatusCode code, const std::string& description) {};
        /**
         * Notifies the delegate that the banner was interacted with.
         */
        virtual void bannerDidInteractWithParams(const std::map<std::string, std::string>& params) {};
        /**
         * Notifies the delegate that the user would be taken out of the application context.
         */
        virtual void userWillLeaveApplicationFromBanner() {};
        /**
         * Notifies the delegate that the banner would be presenting a full screen content.
         */
        virtual void bannerWillPresentScreen() {};
        /**
         * Notifies the delegate that the banner has finished presenting screen.
         */
        virtual void bannerDidPresentScreen() {};
        /**
         * Notifies the delegate that the banner will start dismissing the presented screen.
         */
        virtual void bannerWillDismissScreen() {};
        /**
         * Notifies the delegate that the banner has dismissed the presented screen.
         */
        virtual void bannerDidDismissScreen() {};
        /**
         * Notifies the delegate that the user has completed the action to be incentivised with.
         */
        virtual void bannerRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) = 0;


        /**
         * Notifies the delegate that the interstitial has finished loading
         */
        virtual void interstitialDidFinishLoading() {};
        /**
         * Notifies the delegate that the interstitial has failed to load with some error.
         */
        virtual void interstitialDidFailToLoadWithError(PluginInMobi::SBIMStatusCode code, const std::string& description) {};
        /**
         * Notifies the delegate that the interstitial would be presented.
         */
        virtual void interstitialWillPresent() {};
        /**
         * Notifies the delegate that the interstitial has been presented.
         */
        virtual void interstitialDidPresent() {};
        /**
         * Notifies the delegate that the interstitial has failed to present with some error.
         */
        virtual void interstitialDidFailToPresentWithError(PluginInMobi::SBIMStatusCode code, const std::string& description) {};
        /**
         * Notifies the delegate that the interstitial will be dismissed.
         */
        virtual void interstitialWillDismiss() {};
        /**
         * Notifies the delegate that the interstitial has been dismissed.
         */
        virtual void interstitialDidDismiss() {};
        /**
         * Notifies the delegate that the interstitial has been interacted with.
         */
        virtual void interstitialDidInteractWithParams(const std::map<std::string, std::string>& params) {};
        /**
         * Notifies the delegate that the user has performed the action to be incentivised with.
         */
        virtual void interstitialRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) = 0;
        /**
         * Notifies the delegate that the user will leave application context.
         */
        virtual void userWillLeaveApplicationFromInterstitial() {};

    };
}

#endif
