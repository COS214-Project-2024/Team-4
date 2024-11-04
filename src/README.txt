Qt Design Studio README
=======================

Qt Bridge
---------
Qt Online Installer copies the Qt Bridge installation packages
to the QtDesignStudio\photoshop_bridge and QtDesignStudio\sketch_bridge
folders in the Qt installation folder.

Since Qt Design Studio 2.1, the Qt Bridge also includes support for Figma.
Since Qt Design Studio 3.8, the Figma plugin can be installed as a Figma community plugin.
See: https://www.figma.com/community/plugin/1167809465162924409/Qt-Bridge-for-Figma
You are no longer required to manually load the plugin manifest from QtDesignStudio/figma_bridge.

Since Qt Design Studio 2.3, the Qt Bridge also includes support for Adobe XD.
The Adobe XD plugin can be found in QtDesignStudio\xd_bridge.

The officially supported versions for the Qt Bridges are
Photoshop 23.4 Sketch 93, Figma 116, Adobe XD 51.0.12.

See the product documentation for more information:
https://doc.qt.io/qtdesignstudio/qtbridge-overview.html

Only Qt Design Studio Enterprise license supports the Qt Bridges.

Known Issues in Qt Design Studio 4.6.1
------------------------------------

- Wizards that do not open files trigger error messages (GridView wizards):
  QDS-241 - Wizards show an error message if no file is defined as the file to open.
- Qt Design Studio process hangs on exit in some rare cases (QDS-12794)
