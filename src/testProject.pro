#-------------------------------------------------
#
# Project created by QtCreator 2012-07-13T19:21:55
#
#-------------------------------------------------

#QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:QMAKE_LIBDIR += $$PWD/lib
win32:LIBS += -ladvapi32

LIBS += -lfreetype

TARGET = testProject
TEMPLATE = app


INCLUDEPATH +=  logic       \
                gui         \
                util        \
                common      \
                events      \
                libxpdf     \
                include     \
                include/freetype2    \
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
    libxpdf/goo/GMutex.h \
    logic/documentpdf.h \
    include/ft2build.h \
    include/freetype2/freetype/tttags.h \
    include/freetype2/freetype/tttables.h \
    include/freetype2/freetype/ttnameid.h \
    include/freetype2/freetype/t1tables.h \
    include/freetype2/freetype/ftxf86.h \
    include/freetype2/freetype/ftwinfnt.h \
    include/freetype2/freetype/fttypes.h \
    include/freetype2/freetype/fttrigon.h \
    include/freetype2/freetype/ftsystem.h \
    include/freetype2/freetype/ftsynth.h \
    include/freetype2/freetype/ftstroke.h \
    include/freetype2/freetype/ftsnames.h \
    include/freetype2/freetype/ftsizes.h \
    include/freetype2/freetype/ftrender.h \
    include/freetype2/freetype/ftpfr.h \
    include/freetype2/freetype/ftoutln.h \
    include/freetype2/freetype/ftotval.h \
    include/freetype2/freetype/ftmoderr.h \
    include/freetype2/freetype/ftmodapi.h \
    include/freetype2/freetype/ftmm.h \
    include/freetype2/freetype/ftmac.h \
    include/freetype2/freetype/ftlzw.h \
    include/freetype2/freetype/ftlist.h \
    include/freetype2/freetype/ftlcdfil.h \
    include/freetype2/freetype/ftincrem.h \
    include/freetype2/freetype/ftimage.h \
    include/freetype2/freetype/ftgzip.h \
    include/freetype2/freetype/ftgxval.h \
    include/freetype2/freetype/ftglyph.h \
    include/freetype2/freetype/ftgasp.h \
    include/freetype2/freetype/fterrors.h \
    include/freetype2/freetype/fterrdef.h \
    include/freetype2/freetype/ftchapters.h \
    include/freetype2/freetype/ftcache.h \
    include/freetype2/freetype/ftbitmap.h \
    include/freetype2/freetype/ftbdf.h \
    include/freetype2/freetype/ftbbox.h \
    include/freetype2/freetype/freetype.h \
    include/freetype2/freetype/ttunpat.h \
    include/freetype2/freetype/config/ftoption.h \
    include/freetype2/freetype/config/ftmodule.h \
    include/freetype2/freetype/config/ftheader.h \
    include/freetype2/freetype/config/ftconfig.h \
    include/freetype2/freetype/config/ftstdlib.h

FORMS    += gui/mainwindow.ui
