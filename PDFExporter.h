#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"
#include "Canvas.h"


class PDFExporter : public ExportCanvas {
    public:
        PDFExporter(Canvas* canvas): ExportCanvas(canvas){}
        virtual ~PDFExporter() = default;
        void exportToFile() override;
        void prepareCanvas() override;
        void renderElements() override;
        void saveToFile() override;  
};

#endif // PDFEXPORTER_H