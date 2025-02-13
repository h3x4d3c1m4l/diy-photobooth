part of 'photo_booth.dart';

class MomentoMenuBar extends StatelessWidget {

  final GoRouter router;

  const MomentoMenuBar({super.key, required this.router});

  @override
  Widget build(BuildContext context) {
    AppLocalizations localizations = AppLocalizations.of(context)!;
    return ColoredBox(
      color: Color(0xFFFFFFFF),
      child: MenuBar(
        items: [
          MenuBarItem(title: localizations.genericFile, items: [
            MenuFlyoutSubItem(
              text: Text(localizations.projectsRecent),
              items: (context) {
                return [
                  for (final project in getIt<ProjectManager>().listProjects())
                    MenuFlyoutItem(
                      text: Text(project.name),
                      onPressed: () { getIt<ProjectManager>().open(project.path); },
                    ),
                ];
              },
            ),
            MenuFlyoutItem(text: Text(localizations.projectOpenShort), onPressed: getIt<ProjectManager>().browseOpen, leading: Icon(LucideIcons.folderInput), trailing: shortcut("Ctrl+O")),
            MenuFlyoutItem(text: Text(localizations.projectViewInExplorer), onPressed: () {
              final uri = Uri.parse("file:///${getIt<ProjectManager>().path!.path}");
              launchUrl(uri);
            }, leading: Icon(LucideIcons.folderClosed)),
            MenuFlyoutItem(text: Text(localizations.genericSettings), onPressed: () { GoRouter.of(context).push(SettingsScreen.defaultRoute); }, leading: Icon(LucideIcons.settings), trailing: shortcut("Ctrl+S")),
            MenuFlyoutItem(text: Text(localizations.actionRestoreLiveView), onPressed: () { getIt<LiveViewManager>().restoreLiveView(); }, leading: Icon(LucideIcons.rotateCcw), trailing: shortcut("Ctrl+R")),
            const MenuFlyoutSeparator(),
            MenuFlyoutItem(text: Text(localizations.actionsExit), onPressed: getIt<WindowManager>().close,)
          ]),
          MenuBarItem(title: localizations.genericView, items: [
            MenuFlyoutItem(text: Text(localizations.genericFullScreen), onPressed: () { getIt<WindowManager>().toggleFullscreen(); }, leading: Icon(LucideIcons.expand), trailing: shortcut("Ctrl+F/Alt+Enter")),
            const MenuFlyoutSeparator(),
            MenuFlyoutItem(text: Text(localizations.screensStart), onPressed: () { router.go(StartScreen.defaultRoute); }, leading: Icon(LucideIcons.play), trailing: shortcut("Ctrl+H")),
            MenuFlyoutItem(text: Text(localizations.screensGallery), onPressed: () { router.go(GalleryScreen.defaultRoute); }, leading: Icon(LucideIcons.images)),
            MenuFlyoutItem(text: Text(localizations.screensManualCollage), onPressed: () { router.go(ManualCollageScreen.defaultRoute); }, leading: Icon(LucideIcons.layoutDashboard), trailing: shortcut("Ctrl+M")),
          ]),
          MenuBarItem(title: localizations.genericHelp, items: [
            MenuFlyoutItem(text: Text(localizations.genericDocumentation), onPressed: () { launchUrl(Uri.parse("https://momentobooth.github.io/momentobooth/")); }, leading: Icon(LucideIcons.book)),
            // TODO go to about screen in settings
            MenuFlyoutItem(text: Text(localizations.genericAbout), onPressed: () { GoRouter.of(context).push(SettingsScreen.defaultRoute); }, leading: Icon(LucideIcons.info)),
          ]),
        ],
      ),
    );
  }

}
