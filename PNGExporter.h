#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H
#include "ExportCanvas.h"
#include "Canvas.h"


class PNGExporter : public ExportCanvas{
    private:
        void saveToFile();
};
#endif