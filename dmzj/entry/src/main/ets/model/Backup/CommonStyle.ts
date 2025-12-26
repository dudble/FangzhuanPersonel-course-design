import { DMZJ_COLOR } from './Data';
import router from '@ohos.router'

@Component
export struct dmzjItemStyle{
  private imageSrc: string = "";
  private text: string = "";
  private arrow: string = "arrow.png";

  build() {
    Column(){
      Flex(
        {
          alignItems: ItemAlign.Center,
          justifyContent: FlexAlign.Start
        }
      ){
        Image($rawfile(this.imageSrc)).width('75px').height('75px').margin({left: '50px'})
        Text(this.text).fontSize('18fp').padding('30px')
        Image($rawfile(this.arrow)).width('75px').height('75px').margin({right: '40px'})
      }.height('180px').width('100%')
    }.onClick(() => {
        switch (this.text){
          case "账号与安全" :
            router.pushUrl({ url: 'pages/Login' })
        }
    })
  }
}

@Component
export struct myDivider{
  private style: string = ""

  build(){
    Row(){
      Divider().vertical(false).color(DMZJ_COLOR).strokeWidth(this.style == "1" ? '3px': '23px')
    }.height(this.style == "1" ? '3px' : '23px').width('100%')
  }
}

@Component
export struct MangaItem{

  private  manga_id: number = 0;
  private  cover: string = "";
  private  name: string = "";
  private  state: boolean = true;

  build() {
    Flex(
      {
        direction: FlexDirection.Column,
        justifyContent: FlexAlign.Start
      }
    ){
      Image($rawfile(this.cover)).width(140).height(200)
      Text(this.name).fontSize(20)
        //.fontColor("#ffffff")
      Text(this.state == true? "连载中": "已完结").fontSize(15).fontColor("#ABABAB")
    }
    //.backgroundColor("#FFCCCC")
  }

}

@Component
export struct NewsItem {

  private news_id: number = 0
  private title: string = ""
  private img: string = ""
  private author: string = ""
  private time: string = ""

  build() {
    Column(){
      Flex(
        {
          alignItems: ItemAlign.Center,
          justifyContent: FlexAlign.Start
        }
      ){
        Image($rawfile(this.img)).width('300px').height('210px').margin({left: '50px', right: '50px'})
        Column({space: 8}){
          Text(this.title).fontSize(18)
            //.fontColor("#ffffff")
          Text(this.author).fontSize(12).fontColor("#ABABAB")
        }
        .alignItems(HorizontalAlign.Start)
        .flexGrow(1)

        Text(this.time).fontSize('12fp').margin({right: "50px"}).fontColor("#ABABAB")
      }
      .height('240px').width('100%')

      myDivider()
    }
  }

}