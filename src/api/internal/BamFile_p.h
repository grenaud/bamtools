// ***************************************************************************
// BamFile_p.h (c) 2011 Derek Barnett
// Marth Lab, Department of Biology, Boston College
// ---------------------------------------------------------------------------
// Last modified: 9 September 2011 (DB)
// ---------------------------------------------------------------------------
// Provides BAM file-specific IO behavior
// ***************************************************************************

#ifndef BAMFILE_P_H
#define BAMFILE_P_H

//  -------------
//  W A R N I N G
//  -------------
//
// This file is not part of the BamTools API.  It exists purely as an
// implementation detail. This header file may change from version to version
// without notice, or even be removed.
//
// We mean it.

#include <api/internal/ILocalIODevice_p.h>
#include <string>

namespace BamTools {
namespace Internal {

class BamFile : public ILocalIODevice {

    // ctor & dtor
    public:
        BamFile(const std::string& filename);
        ~BamFile(void);

    // ILocalIODevice implementation
    public:
        void Close(void);
        bool IsRandomAccess(void) const;
        bool Open(const IBamIODevice::OpenMode mode);
        bool Seek(const int64_t& position);

    // data members
    private:
        std::string m_filename;
};

} // namespace Internal
} // namespace BamTools

#endif // BAMFILE_P_H
