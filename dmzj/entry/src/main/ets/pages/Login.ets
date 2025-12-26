import { User } from '../model/User'
import router from '@ohos.router'
import promptAction from '@ohos.promptAction'

@Entry
@Component
export struct LoginPage {
  private username: string = ""
  private password: string = ""
  @State errorMessage: string = ""

  build() {
    Column({ space: 20 }) {
      Text("登录").fontSize(22)

      TextInput({ placeholder: "用户名" })
        .onChange(v => {
          this.username = v
          this.errorMessage = ""
        })

      TextInput({ placeholder: "密码" })
        .type(InputType.Password)
        .onChange(v => {
          this.password = v
          this.errorMessage = ""
        })

      Button("确认登录")
        .backgroundColor("#114514")
        .onClick(() => {
          if (this.username == "dudble" && this.password == "114514") {
            User.login(this.username)
            router.back()
          }
          else{
            this.errorMessage = "用户名或密码不正确，请重试"
          }
        })

      Text(this.errorMessage)
    }
    .padding(30)
    .width('100%')
    .height('100%')
  }
}
