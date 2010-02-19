/* medToolBoxContainer.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Oct 26 21:51:08 2009 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Feb 19 18:25:16 2010 (+0100)
 *           By: Julien Wintz
 *     Update #: 16
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "medFlicker.h"
#include "medToolBox.h"
#include "medToolBoxContainer.h"

#include <QtGui>

class medToolBoxContainerPrivate
{
public:
    QFrame *container;
    QVBoxLayout *layout;
};

medToolBoxContainer::medToolBoxContainer(QWidget *parent) : QScrollArea(parent), d(new medToolBoxContainerPrivate)
{
    d->container = new QFrame(this);
    d->container->setObjectName("medToolBoxContainer");

    d->layout = new QVBoxLayout(d->container);
    d->layout->setContentsMargins(2, 4, 0, 0);
    d->layout->addStretch(1);

    this->setFrameStyle(QFrame::NoFrame);
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->setWidget(d->container);
    this->setWidgetResizable(true);

    medFlicker *flicker = new medFlicker(this);
    flicker->activateOn(this);
}

medToolBoxContainer::~medToolBoxContainer(void)
{
    delete d;

    d = NULL;
}

void medToolBoxContainer::addToolBox(medToolBox *toolBox)
{
    d->layout->insertWidget(d->layout->count()-1, toolBox, 0, Qt::AlignTop);
}

void medToolBoxContainer::removeToolBox(medToolBox *toolBox)
{
    d->layout->removeWidget(toolBox);
}
