/***************************************************************************
 *    ISimulatorFactory interface.                                         *
 *     A common interface for all document simulator factories in KTechLab *
 *    Copyright (c) 2010 Zoltan Padrah                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef ISIMULATORFACTORY_H
#define ISIMULATORFACTORY_H

#include "ktlinterfacesexport.h"


#include <QObject>

namespace KTechLab {

    class ISimulator;
    class IDocument;

/**
 * \brief common interface for all the simulator factories
 * The main purpose of the \ref ISimulator factores is to register
 * themselves on the \ref ISimulationManager and then create
 * ISimulators as needed
 *
 * One factory type can support only one simulation type and
 * only one document type
 */
class KTLINTERFACES_EXPORT ISimulatorFactory : public QObject {
    Q_OBJECT

    public:
    // virtual desctructor
      virtual ~ISimulatorFactory();

    /**
     * \return the type simulation where this factory can create ISimulators
     */
      virtual QString *simulationType() = 0;

    /**
     * \return the name of the document mimetype, for which the factory can
     * create ISimulators
     */
      virtual QString *supportedDocumentMimeTypeName() = 0;

     /**
      * \return a new simulator for a given document, and the supported 
      *     simulation type
      * The document should be of the same type as the supported one
      */
     virtual ISimulator *create(IDocument *) = 0;

};

}

#endif // ISIMULATORFACTORY_H
