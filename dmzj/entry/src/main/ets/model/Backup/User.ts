
export class User {

  static get isLogin(): boolean {
    return AppStorage.get<boolean>('isLogin') ?? false;
  }

  static get username(): string {
    return AppStorage.get<string>('username') ?? '';
  }

  // 登录
  static login(name: string) {
    AppStorage.setOrCreate<boolean>('isLogin', true);
    AppStorage.setOrCreate<string>('username', name);
    console.log('[User] 登录成功，用户名:', name);
  }

  // 退出
  static logout() {
    AppStorage.setOrCreate<boolean>('isLogin', false);
    AppStorage.setOrCreate<string>('username', '');
    console.log('[User] 已退出登录');
  }

  static isGuest(): boolean {
    return !User.isLogin;
  }
}