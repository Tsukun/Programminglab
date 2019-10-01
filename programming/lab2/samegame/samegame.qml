import "samegame.js" as SameGame
import QtQuick 2.9
Rectangle { // "холст" главного окна приложения в виде приямоугольника
 id: screen // его уникальное имя
 width: 490; height: 720 // размеры прямоугольника
 SystemPalette { id: activePalette }
 Item { id: gameCanvas
     property int score: 0
     property int blockSize: 40
     width: parent.width - (parent.width % blockSize)
     height: parent.height - (parent.height % blockSize)
     anchors.centerIn: parent
     MouseArea {
     anchors.fill: parent
     onClicked: SameGame.handleClick(mouse.x, mouse.y)
     }
 Image { // Изображение
 id: background
 anchors.fill: parent // Должно целиком заполнить родительский элемент
 source: "shared/pics/background.jpg"
 fillMode: Image.PreserveAspectCrop // изображение растягивается, если нужно - обрезается
 }
 }
 Dialog {
  id: dialog
  anchors.centerIn: parent
  z: 100
  }

 Rectangle {
 id: toolBar // панель инструментов
 width: parent.width; height: 30
 color: activePalette.window
 anchors.bottom: screen.bottom
 Button { // Наш новый компонент "Кнопка", который нужно будет создать
 anchors { left: parent.left; verticalCenter: parent.verticalCenter }
 text: "New Game"
 onClicked: SameGame.startNewGame()
 }
 Text {
 id: score
 anchors { right: parent.right; verticalCenter: parent.verticalCenter
}
 text:"Score:" + gameCanvas.score
 }
}
}

