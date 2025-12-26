import { MyPage } from './MyPage'
import { MangaPage } from './MangaPage'
import { InformationPage } from './InformationPage'
import { ShelfPage } from './ShelfPage'

@Entry
@Component
struct Index {

  @Provide currentPage: number = 0;
  @State currentIndex: number = 0;


  build() {
    Column(){
      Tabs({
        index: this.currentIndex,
        barPosition: BarPosition.End
      }) {

        TabContent() {
          MangaPage()
        }
        .tabBar(this.TabBuilder('漫画', 0, $r('app.media.book_'), $r('app.media.book')))

        TabContent() {
          InformationPage()
        }
        .tabBar(this.TabBuilder('资讯', 1, $r('app.media.file_'), $r('app.media.file')))

        TabContent() {
          ShelfPage()
        }
        .tabBar(this.TabBuilder('书架', 2, $r('app.media.shop_'), $r('app.media.shop')))

        TabContent() {
          MyPage()
        }
        .tabBar(this.TabBuilder('我的', 3, $r('app.media.my_'), $r('app.media.my')))


      }
      .barMode(BarMode.Fixed)
      .onChange((Index: number) => {
        this.currentIndex = Index;
      })
    }
  }
  @Builder TabBuilder(title: string, targetIndex: number, selectedImg: Resource, normalImg: Resource)
  {
    Column(){
      Image(this.currentIndex == targetIndex ? selectedImg : normalImg).size({width: 25, height: 25});
      Text(title).fontColor(this.currentIndex == targetIndex ? '#1698CE' : '#6b6b6b')
    }.width('100%').height(50).justifyContent(FlexAlign.Center);
  }
}