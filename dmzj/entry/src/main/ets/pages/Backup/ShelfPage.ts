import { MangaItem } from "../model/CommonStyle"
import { CONTACTS, Manga, DMZJ_COLOR } from "../model/Data"
import { User } from "../model/User"
import router from "@ohos.router"

@Component
export struct ShelfPage{

  @StorageLink('isLogin') isLogin: boolean = false
  @StorageLink('username') currentUsername: string = ''


  build() {

    if(!this.isLogin){
      Column({ space: 15 }) {
        Text("您还未登录，请先登录查看书架")
          .fontSize(16)
          .fontColor("#666666")
        Button("去登录")
          .backgroundColor("#666666")
          .onClick(() => {
            router.pushUrl({ url: 'pages/Login' })
              .catch((err: Error) => {
              console.error(`跳转失败,信息: ${err.message}`)
            })
          })
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Center)
    }
    else{
      Column(){

        Flex(
          {
            alignItems: ItemAlign.Center,
            justifyContent: FlexAlign.Center
          }
        ){
          Text("我的漫画").fontSize('18fp').padding('20px')
        }.height('120px')

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
        .columnsGap(10)
        .rowsGap(10)
        .padding(10)
      }
    }
  }

}