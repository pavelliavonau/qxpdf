#-------------------------------------------------
#
# Project created by QtCreator 2012-07-13T19:21:55
#
#-------------------------------------------------

#QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_LIBDIR += $$PWD/lib

LIBS += -lfreetype

#-lfreetype  -lpaper

TARGET = testProject
TEMPLATE = app


INCLUDEPATH +=  logic       \
                gui         \
                util        \
                common      \
                events      \
                libxpdf     \
                include     \
                include/freetype    \
                include/freetype/config    \
                include/freetype/internal    \
                include/freetype/internal/services    \
                libxpdf/goo     \
                libxpdf/xpdf    \
                libxpdf/splash  \
                libxpdf/fofi


SOURCES += main.cpp\
        gui/mainwindow.cpp \
    libxpdf/xpdf/PDFCore.cc \
    libxpdf/xpdf/PDFDoc.cc \
    libxpdf/goo/GString.cc \
    libxpdf/xpdf/Page.cc \
    libxpdf/xpdf/Catalog.cc \
    libxpdf/xpdf/Object.cc \
    libxpdf/goo/gmem.cc \
    libxpdf/xpdf/Array.cc \
    libxpdf/xpdf/Dict.cc \
    libxpdf/xpdf/Stream.cc \
    libxpdf/xpdf/XRef.cc \
    libxpdf/goo/GList.cc \
    libxpdf/splash/SplashPattern.cc \
    libxpdf/splash/SplashPath.cc \
    libxpdf/splash/SplashBitmap.cc \
    libxpdf/xpdf/Error.cc \
    libxpdf/xpdf/GlobalParams.cc \
    libxpdf/splash/SplashClip.cc \
    libxpdf/xpdf/Link.cc \
    libxpdf/xpdf/CoreOutputDev.cc \
    libxpdf/xpdf/TextOutputDev.cc \
    libxpdf/xpdf/GfxFont.cc \
    libxpdf/xpdf/OutputDev.cc \
    libxpdf/xpdf/SplashOutputDev.cc \
    libxpdf/xpdf/GfxState.cc \
    libxpdf/xpdf/Function.cc \
    libxpdf/splash/Splash.cc \
    libxpdf/xpdf/Lexer.cc \
    libxpdf/xpdf/OptionalContent.cc \
    libxpdf/xpdf/Outline.cc \
    libxpdf/xpdf/SecurityHandler.cc \
    libxpdf/xpdf/Parser.cc \
    libxpdf/xpdf/Gfx.cc \
    libxpdf/xpdf/Annot.cc \
    libxpdf/goo/gfile.cc \
    libxpdf/xpdf/PDFDocEncoding.cc \
    libxpdf/xpdf/JBIG2Stream.cc \
    libxpdf/xpdf/JPXStream.cc \
    libxpdf/splash/SplashScreen.cc \
    libxpdf/goo/GHash.cc \
    libxpdf/xpdf/UnicodeMap.cc \
    libxpdf/xpdf/BuiltinFontTables.cc \
    libxpdf/xpdf/CMap.cc \
    libxpdf/xpdf/FontEncodingTables.cc \
    libxpdf/xpdf/CharCodeToUnicode.cc \
    libxpdf/xpdf/BuiltinFont.cc \
    libxpdf/splash/SplashXPathScanner.cc \
    libxpdf/splash/SplashXPath.cc \
    libxpdf/xpdf/UnicodeTypeTable.cc \
    libxpdf/fofi/FoFiType1C.cc \
    libxpdf/fofi/FoFiType1.cc \
    libxpdf/fofi/FoFiTrueType.cc \
    libxpdf/fofi/FoFiIdentifier.cc \
    libxpdf/fofi/FoFiBase.cc \
    libxpdf/splash/SplashFontEngine.cc \
    libxpdf/splash/SplashFontFile.cc \
    libxpdf/splash/SplashFontFileID.cc \
    libxpdf/xpdf/Decrypt.cc \
    libxpdf/xpdf/JArithmeticDecoder.cc \
    libxpdf/xpdf/PSTokenizer.cc \
    libxpdf/fofi/FoFiEncodings.cc \
    libxpdf/splash/SplashT1FontEngine.cc \
    libxpdf/splash/SplashFTFontEngine.cc \
    libxpdf/splash/SplashFTFontFile.cc \
    libxpdf/xpdf/NameToCharCode.cc \
    libxpdf/splash/SplashState.cc \
    libxpdf/splash/SplashFont.cc \
    libxpdf/splash/SplashFTFont.cc \
    logic/pdfreaderlogic.cpp \
    gui/pagegraphicsitem.cpp \
    events/pagegraphicsitemevent.cpp \
    logic/documentpdf.cpp

HEADERS  += gui/mainwindow.h \
    libxpdf/xpdf/PDFCore.h \
    libxpdf/xpdf/PDFDoc.h \
    libxpdf/aconf.h \
    libxpdf/aconf2.h \
    libxpdf/goo/GString.h \
    libxpdf/goo/gtypes.h \
    libxpdf/xpdf/Page.h \
    libxpdf/xpdf/Catalog.h \
    libxpdf/xpdf/CharTypes.h \
    libxpdf/xpdf/Object.h \
    libxpdf/goo/gmem.h \
    libxpdf/xpdf/Array.h \
    libxpdf/xpdf/Dict.h \
    libxpdf/xpdf/Stream.h \
    libxpdf/xpdf/XRef.h \
    libxpdf/splash/SplashTypes.h \
    libxpdf/goo/GList.h \
    libxpdf/splash/SplashPattern.h \
    libxpdf/splash/SplashPath.h \
    libxpdf/splash/SplashBitmap.h \
    libxpdf/splash/Splash.h \
    libxpdf/xpdf/ErrorCodes.h \
    libxpdf/xpdf/Error.h \
    libxpdf/xpdf/GlobalParams.h \
    libxpdf/splash/SplashClip.h \
    libxpdf/xpdf/config.h \
    libxpdf/xpdf/Link.h \
    libxpdf/xpdf/CoreOutputDev.h \
    libxpdf/xpdf/TextOutputDev.h \
    libxpdf/xpdf/GfxFont.h \
    libxpdf/xpdf/OutputDev.h \
    libxpdf/xpdf/SplashOutputDev.h \
    libxpdf/xpdf/GfxState.h \
    libxpdf/xpdf/Function.h \
    libxpdf/xpdf/Lexer.h \
    libxpdf/xpdf/OptionalContent.h \
    libxpdf/xpdf/Outline.h \
    libxpdf/xpdf/SecurityHandler.h \
    libxpdf/xpdf/Parser.h \
    libxpdf/xpdf/Gfx.h \
    libxpdf/xpdf/Annot.h \
    libxpdf/goo/gfile.h \
    libxpdf/xpdf/PDFDocEncoding.h \
    libxpdf/xpdf/Stream-CCITT.h \
    libxpdf/xpdf/JBIG2Stream.h \
    libxpdf/xpdf/JPXStream.h \
    libxpdf/splash/SplashScreen.h \
    libxpdf/splash/SplashErrorCodes.h \
    libxpdf/goo/GHash.h \
    libxpdf/xpdf/UnicodeMap.h \
    libxpdf/xpdf/BuiltinFontTables.h \
    libxpdf/xpdf/CMap.h \
    libxpdf/xpdf/FontEncodingTables.h \
    libxpdf/xpdf/CharCodeToUnicode.h \
    libxpdf/xpdf/BuiltinFont.h \
    libxpdf/xpdf/UnicodeMapTables.h \
    libxpdf/xpdf/UTF8.h \
    libxpdf/xpdf/NameToUnicodeTable.h \
    libxpdf/splash/SplashXPathScanner.h \
    libxpdf/splash/SplashXPath.h \
    libxpdf/xpdf/UnicodeTypeTable.h \
    libxpdf/fofi/FoFiType1.h \
    libxpdf/fofi/FoFiTrueType.h \
    libxpdf/fofi/FoFiIdentifier.h \
    libxpdf/fofi/FoFiType1C.h \
    libxpdf/fofi/FoFiBase.h \
    libxpdf/splash/SplashGlyphBitmap.h \
    libxpdf/splash/SplashFont.h \
    libxpdf/splash/SplashFontEngine.h \
    libxpdf/splash/SplashFontFile.h \
    libxpdf/splash/SplashFontFileID.h \
    libxpdf/xpdf/Decrypt.h \
    libxpdf/xpdf/JArithmeticDecoder.h \
    libxpdf/xpdf/PSTokenizer.h \
    libxpdf/fofi/FoFiEncodings.h \
    libxpdf/splash/SplashT1FontEngine.h \
    libxpdf/splash/SplashFTFontEngine.h \
    libxpdf/splash/SplashFTFontFile.h \
    libxpdf/splash/SplashFTFont.h \
    libxpdf/xpdf/NameToCharCode.h \
    libxpdf/splash/SplashState.h \
    common/types.h \
    logic/pdfreaderlogic.h \
    gui/pagegraphicsitem.h \
    events/pagegraphicsitemevent.h \    
#    include/ft2build.h \
#    include/freetype/tttags.h \
#    include/freetype/tttables.h \
#    include/freetype/ttnameid.h \
#    include/freetype/t1tables.h \
#    include/freetype/ftxf86.h \
#    include/freetype/ftwinfnt.h \
#    include/freetype/fttypes.h \
#    include/freetype/fttrigon.h \
#    include/freetype/ftsystem.h \
#    include/freetype/ftsynth.h \
#    include/freetype/ftstroke.h \
#    include/freetype/ftsnames.h \
#    include/freetype/ftsizes.h \
#    include/freetype/ftrender.h \
#    include/freetype/ftpfr.h \
#    include/freetype/ftoutln.h \
#    include/freetype/ftotval.h \
#    include/freetype/ftmoderr.h \
#    include/freetype/ftmodapi.h \
#    include/freetype/ftmm.h \
#    include/freetype/ftmac.h \
#    include/freetype/ftlzw.h \
#    include/freetype/ftlist.h \
#    include/freetype/ftlcdfil.h \
#    include/freetype/ftincrem.h \
#    include/freetype/ftimage.h \
#    include/freetype/ftgzip.h \
#    include/freetype/ftgxval.h \
#    include/freetype/ftglyph.h \
#    include/freetype/ftgasp.h \
#    include/freetype/fterrors.h \
#    include/freetype/fterrdef.h \
#    include/freetype/ftcid.h \
#    include/freetype/ftchapters.h \
#    include/freetype/ftcache.h \
#    include/freetype/ftbitmap.h \
#    include/freetype/ftbdf.h \
#    include/freetype/ftbbox.h \
#    include/freetype/ftadvanc.h \
#    include/freetype/freetype.h \
#    include/freetype/ttunpat.h \
#    include/freetype/config/ftoption.h \
#    include/freetype/config/ftmodule.h \
#    include/freetype/config/ftheader.h \
#    include/freetype/config/ftconfig.h \
#    include/freetype/config/ftstdlib.h \
#    include/freetype/internal/t1types.h \
#    include/freetype/internal/sfnt.h \
#    include/freetype/internal/pshints.h \
#    include/freetype/internal/psaux.h \
#    include/freetype/internal/pcftypes.h \
#    include/freetype/internal/internal.h \
#    include/freetype/internal/ftvalid.h \
#    include/freetype/internal/fttrace.h \
#    include/freetype/internal/ftstream.h \
#    include/freetype/internal/ftserv.h \
#    include/freetype/internal/ftrfork.h \
#    include/freetype/internal/ftobjs.h \
#    include/freetype/internal/ftmemory.h \
#    include/freetype/internal/ftgloadr.h \
#    include/freetype/internal/ftdriver.h \
#    include/freetype/internal/ftdebug.h \
#    include/freetype/internal/ftcalc.h \
#    include/freetype/internal/autohint.h \
#    include/freetype/internal/tttypes.h \
#    include/freetype/internal/services/svwinfnt.h \
#    include/freetype/internal/services/svttglyf.h \
#    include/freetype/internal/services/svtteng.h \
#    include/freetype/internal/services/svttcmap.h \
#    include/freetype/internal/services/svsfnt.h \
#    include/freetype/internal/services/svpsinfo.h \
#    include/freetype/internal/services/svpscmap.h \
#    include/freetype/internal/services/svpostnm.h \
#    include/freetype/internal/services/svpfr.h \
#    include/freetype/internal/services/svotval.h \
#    include/freetype/internal/services/svmm.h \
#    include/freetype/internal/services/svkern.h \
#    include/freetype/internal/services/svgxval.h \
#    include/freetype/internal/services/svgldict.h \
#    include/freetype/internal/services/svcid.h \
#    include/freetype/internal/services/svbdf.h \
#    include/freetype/internal/services/svxf86nm.h \
    libxpdf/goo/GMutex.h \
    logic/documentpdf.h

FORMS    += gui/mainwindow.ui

OTHER_FILES +=
