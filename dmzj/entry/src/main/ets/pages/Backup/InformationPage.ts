import { NewsItem } from '../model/CommonStyle'
import {  SWIPER_DATA, News, NEWS_CON } from '../model/Data'

@Component
export struct InformationPage{


  build() {

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

        List() {
          ForEach(NEWS_CON, (item: News) => {
            ListItem() {
              NewsItem({
                news_id: item.id,
                img: item.img,
                title: item.name,
                author: item.author,
                time: item.time
              })
            }
          }, (item: News) => item.id.toString())
        }
      }
    }
    .width('100%')
    .height('100%')
    .padding({ top: 0 })
  }

}