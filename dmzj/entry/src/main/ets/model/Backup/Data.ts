export const CONTACTS: Manga[] = [
  {
    id: 1,
    cover: "1.jpg",
    name: "六亿年博物旅",
    state: true
  },
  {
    id: 2,
    cover: "2.jpg",
    name: "电锯人",
    state: false
  },
  {
    id: 3,
    cover: "3.jpg",
    name: "孤独摇滚",
    state: true
  },
  {
    id: 4,
    cover: "4.jpg",
    name: "黄昏游记",
    state: true
  },
  {
    id: 5,
    cover: "5.jpg",
    name: "樱开二度",
    state: true
  },
  {
    id: 6,
    cover: "6.jpg",
    name: "你也特",
    state: true
  },
]

export const NEWS_CON: News[] = [
  {
    id: 1,
    img: "head1.png",
    name: "哦no妈咪何意味",
    author: "织田信长",
    time: "11:45",
    isTop: true
  },
  {
    id: 2,
    img: "head2.jpg",
    name: "哦no爸比何意味",
    author: "上杉谦信",
    time: "14:19",
    isTop: true
  },
  {
    id: 3,
    img: "head3.jpg",
    name: "哈基米哦那没路多",
    author: "武田信玄",
    time: "19:19",
    isTop: true
  },
  {
    id: 4,
    img: "head3.jpg",
    name: "哈基米哦那没路多",
    author: "武田信玄",
    time: "19:19",
    isTop: false
  },
  {
    id: 5,
    img: "head2.jpg",
    name: "哦no爸比何意味",
    author: "上杉谦信",
    time: "14:19",
    isTop: false
  },
  {
    id: 6,
    img: "head1.png",
    name: "哦no妈咪何意味",
    author: "织田信长",
    time: "11:45",
    isTop: false
  },
]

export const SWIPER_DATA: News[] =
  NEWS_CON.filter(item => item.isTop)


export class News {
  id: number = 0;
  img: string = ""
  name: string = ""
  author: string = "";
  time: string = "";
  isTop: boolean = true
}

export class Manga {
  id: number = 0;
  cover: string = "";
  name: string = "";
  state: boolean = true;
}

export const DMZJ_COLOR: string = "#ededed"

