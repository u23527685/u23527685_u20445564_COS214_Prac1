#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"
#include "Canvas.h"


class PDFExporter : public ExportCanvas {
    private:
        void saveToFile();
};

#endif // PDFEXPORTER_H