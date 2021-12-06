pragma Singleton
import QtQuick 2.11

QtObject {
    id: root
    // zdefiniowanie kolorów
    property string bgColor: "#D1DBE1"
    property string mainColor: "#00D1A9"
    property string inactiveColor: "#A8A8A8"


    // zdefiniowanie ściezki do obrazków
    property string imgPath: "../../assets/"

    function image(name) {
        return Qt.resolvedUrl(imgPath + name + ".png");
    }

    // zdefiniowanie czcionek
    property string fontConstrastColor: "#FFFFFF"
    property string fontPrimaryColor: "#1E272E"
    property string fontSecondaryColor: "#AAAAAA"

    // zdefiniowanie rozmiarów czcionek
    property int fontSizeS: 14
    property int fontSizeM: 18
    property int fontSizeL: 24

    // zdefiniowanie rodziny czcionek
    property string fontFamilyRegular: quicksandBook.name
    property string fontFamilyBold: quicksandBold.name

    property FontLoader quicksandBook: FontLoader {
        source: "../../assets/fonts/Quicksand-Regular.otf"
    }

    property FontLoader quicksandBold: FontLoader {
        source: "../../assets/fonts/Quicksand-Bold.otf"
    }

}
