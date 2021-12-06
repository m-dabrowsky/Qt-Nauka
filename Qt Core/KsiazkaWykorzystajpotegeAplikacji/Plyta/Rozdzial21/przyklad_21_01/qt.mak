QT_MOC_UI_RCC=qt-moc-ui-rcc.exe

all-before: qt_moc_ui_rcc $(patsubst %.cpp,%.o,$(wildcard moc_*.cpp))

qt_moc_ui_rcc:
	$(QT_MOC_UI_RCC)

moc_%.o: moc_%.cpp
	$(CPP) -c $< -o $@ $(CXXFLAGS)



