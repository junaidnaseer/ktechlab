/***************************************************************************
 *   Copyright (C) 2013 Zoltan Padrah <zoltan_padrah@users.sf.net>         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include <QApplication>

#include "mainwindowqt.h"

#include "interfaces/kcomponentdata.h"
#include "plugins/circuit/ktlcircuitplugin_qt.h"

using namespace KTechLab;

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	app.setOrganizationName("KTechLab Project");
	app.setApplicationName("KTechLab - Qt version");

    KComponentData componentData;
    QVariantList args;
    KTLCircuitPluginQt ktlCircuitPlugin(componentData, &app, args);

    MainWindowQt mainWindow(app, ktlCircuitPlugin);
	mainWindow.show();
	return app.exec();
}
