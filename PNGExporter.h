#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H
#include "ExportCanvas.h"
#include "Canvas.h"


class PNGExporter : public ExportCanvas{
    public:
        PNGExporter(Canvas* canvas): ExportCanvas(canvas){}
        void saveToFile() override;
        void prepareCanvas() override;
        void renderElements() override;
        virtual ~PNGExporter() = default;
};
#endif