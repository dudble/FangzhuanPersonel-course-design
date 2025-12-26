import { MangaItem } from '../model/CommonStyle'
import { CONTACTS, Manga, SWIPER_DATA, News } from '../model/Data'

@Component
export struct MangaPage{

  build() {
    Flex(){
      Scroll() {
        Column({ space: 20 }) {

          Swiper() {
            ForEach(SWIPER_DATA, (item: News) => {
              Image($rawfile(item.img))
                .height('100%')
                .width('100%')
            }, (item: News) => item.id.toString())
          }
          .autoPlay(true) //自动轮播
          .height(200)

          Grid() {
            ForEach(CONTACTS, (item: Manga) => {
              GridItem() {
                MangaItem({
                  manga_id: item.id,
                  cover: item.cover,
                  name: item.name,
                  state: item.state
                })
              }
            }, (item: Manga) => item.id.toString())
          }
          .columnsTemplate('1fr 1fr')
          .columnsGap(5)
          .rowsGap(20)
        }
      }
      .width('100%')
      .height('100%')
    }
    .width('100%')
    .height('100%')
  }


}