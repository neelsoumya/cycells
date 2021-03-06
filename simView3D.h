/************************************************************************
 *                                                                      *
 * Copyright (C) 2007  Christina Warrender and Drew Levin               *
 *                                                                      *
 * This file is part of QtCyCells.                                      *
 *                                                                      *
 * QtCyCells is free software; you can redistribute it and/or modify it *
 * under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * QtCyCells is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 * GNU General Public License for more details.                         *
 *                                                                      *
 * You should have received a copy of the GNU General Public License    *
 * along with QtCyCells; if not, write to the Free Software Foundation, *
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA        *
 *                                                                      *
 ************************************************************************/
/************************************************************************
 * File simView3D.h                                                     *
 *   Declarations for SimView3D class                                   * 
 *   Derived from abstract class SimView                                *
 ************************************************************************/

#ifndef _SIMVIEW3D_H_
#define _SIMVIEW3D_H_

#include "simView.h"
#include <GL/gl.h>
#include <QMouseEvent>

class Tissue;
class Molecule;

class SimView3D : public SimView   
{
  public:
    //--------------------------- CREATORS --------------------------------- 
    SimView3D(QWidget *parent, int x, int y, int w, int h, const Tissue *t);

    //------------------------- MANIPULATORS -------------------------------
    void render();

  private:
    const Tissue *m_tissuep;    // Pointer to model
    bool m_first;               // Flag for first call to render

    // Local copies of model info needed for drawing
		int m_xsize, m_ysize, m_zsize, m_maxlength;

    double *m_cellSizes;			  // Radii in microns

    GLUquadricObj *quadratic;     

		bool m_mousedown;           // Used to track mouse dragging
		QPoint oldPos;

		double m_anglex;            // View Angles (horizontal and vertical)
		double m_angley;
		double m_zoom;

		int frame;
    char time_string[256];

    // private functions
    void renderCells();
    void drawCell();
    void renderMolecules();
    void drawGrid();
    void drawBorder();
    void drawTime();

		void saveImage();

		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void wheelEvent(QWheelEvent *event);
};

#endif // _SIMVIEW3D_H_

