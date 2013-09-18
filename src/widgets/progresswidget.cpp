/***************************************************************************
 *   Copyright (C) 2008 - 2009 by Dario Freddi                             *
 *   drf@chakra-project.org                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#include "progresswidget.h"
#include <QMovie>


ProgressWidget::ProgressWidget(QWidget *parent)
        : AbstractPage(parent)
{
    ui.setupUi(this);
}

ProgressWidget::~ProgressWidget()
{
}

void ProgressWidget::setProgressWidgetText(const QString &text)
{
    ui.label->setText(text);
}

void ProgressWidget::setProgressWidgetBusy()
{
    ui.progressBar->setVisible(false);
    m_busyAnim = new QMovie(":Images/images/busywidget.gif");
    m_busyAnim->start();
    ui.busyLabel->setMovie(m_busyAnim);
    ui.busyLabel->setVisible(true);
}

void ProgressWidget::updateProgressWidget(int percentage)
{
    ui.progressBar->setValue(percentage);
}

void ProgressWidget::createWidget()
{
    ui.busyLabel->setVisible(false);
}

#include "progresswidget.moc"
