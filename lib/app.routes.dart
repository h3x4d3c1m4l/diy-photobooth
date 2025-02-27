part of 'app.dart';

List<GoRoute> _rootRoutes = [
  _onboardingRoute,
  _photoBoothRoute,
  _settingsRoute,
];

GoRoute _onboardingRoute = GoRoute(
  path: "/onboarding",
  pageBuilder: (context, state) {
    return NoTransitionPage(
      key: state.pageKey,
      //enableTransitionOut: true,
      child: const OnboardingScreen(),
    );
  },
);

GoRoute _photoBoothRoute = GoRoute(
  path: "/photo_booth",
  pageBuilder: (context, state) {
    return SettingsBasedTransitionPage.fromSettings(
      key: state.pageKey,
      enableTransitionOut: false,
      child: const PhotoBooth(),
    );
  },
);

GoRoute _settingsRoute = GoRoute(
  path: "/settings",
  pageBuilder: (context, state) {
    return SettingsBasedTransitionPage.fromSettings(
      key: state.pageKey,
      opaque: false,
      child: const FullScreenPopup(
        child: SettingsScreen(),
      ),
      barrierDismissible: true,
    );
  },
);
