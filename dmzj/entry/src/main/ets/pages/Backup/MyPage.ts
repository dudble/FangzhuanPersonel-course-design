import { dmzjItemStyle, myDivider} from '../model/CommonStyle'
import { User } from '../model/User'

@Component
export struct MyPage {
  private imageTitle: string = "title.jpg"
  @StorageLink('isLogin') isLogin: boolean = false
  @StorageLink('username') currentUsername: string = ''

  build(){
    Column(){

      if(this.isLogin){
        Image($rawfile(this.imageTitle)).height(230).width('100%')
        myDivider()
        myDivider()
      }

      dmzjItemStyle({imageSrc: "user.svg", text: "个人中心"})
      myDivider()
      dmzjItemStyle({imageSrc: "lock.svg", text: "账号与安全"})
      myDivider()
      dmzjItemStyle({imageSrc: "history.svg", text: "历史记录"})
      myDivider()
      dmzjItemStyle({imageSrc: "download.svg", text: "下载记录"})
      myDivider()
      dmzjItemStyle({imageSrc: "about.svg", text: "关于我们"})
      myDivider()

    }.alignItems(HorizontalAlign.Start).width('100%').height('100%')
  }
}