# ACM/XCPC 算法竞赛学习资料库（全站离线版）

汇总 11 个 ACM/XCPC 相关开源仓库的完整学习资料，全部内容**站内收录、无需外链**：算法笔记全文、281 份讲义 PDF 原文、304+ 段模板代码原文、图片原文、PPT/Word 等文档原文，均可直接在浏览器中打开或下载。

## 内容统计

| 类别 | 数量 |
|---|---|
| 开源仓库 | 11 个 |
| 笔记（md 转 HTML 阅读页） | 120 篇 |
| 讲义 PDF | 281 份 |
| 模板/代码文件 | 300+ 段 |
| 图片（含笔记配图） | 100+ 张 |
| 其他文档（PPT/Word/TXT 等） | 大量 |

## 目录结构

```
├── index.html              # 门户首页（搜索/笔记/讲义/代码/仓库索引）
├── assets/
│   ├── style.css           # 全站样式（青绿学术风）
│   ├── portal_data.js      # 门户索引数据
│   └── data.json           # 全量元数据（构建用）
├── lectures/               # 精讲讲义：99 页 PDF + 网页版
└── repos/
    └── <仓库id>/
        ├── index.html      # 仓库详情页（笔记/讲义/代码/图片/文件分区）
        ├── notes/          # md 转换的独立 HTML 阅读页
        ├── pdfs/           # PDF 原文（浏览器可直接预览）
        ├── code/           # 代码原文
        ├── images/         # 图片原文（含笔记配图、外链图本地化）
        └── files/          # 其余文档原文（PPT/Word/TXT 等）
```

所有页面均为静态文件，互相以相对路径链接。

## 部署到 GitHub Pages（约 5 分钟）

1. **新建仓库**：登录 GitHub → New repository，仓库名随意（如 `acm-handbook`），选 Public。
2. **上传**：把本文件夹的全部内容（含 `index.html`、`assets/`、`repos/`、`lectures/`）上传到仓库根目录。推荐用桌面端 [GitHub Desktop](https://desktop.github.com/) 或网页端 Upload files（文件较多时建议用 Git 命令行：`git init` → `git add .` → `git commit` → 推送到远程）。
3. **开启 Pages**：仓库 Settings → 左侧 Pages → Source 选 `Deploy from a branch` → Branch 选 `main`（或 `master`）+ 目录 `/ (root)` → Save。
4. **访问**：等待 1~2 分钟，打开 `https://<你的用户名>.github.io/<仓库名>/` 即完成。

> 提示：GitHub 单文件上限 100MB，本包内所有文件均远低于该限制，可放心上传。

## 本地使用

无需服务器：直接双击 `index.html` 即可在浏览器中浏览全站（本地 file:// 打开同样完整可用）。

## 说明

- 仓库卡片中的 GitHub/Gitee 地址为说明性文字，全部资料已站内收录，不依赖外链访问。
- 个别笔记原文引用的第三方外链图片（数学公式、排序动画等）已尽量下载本地化；极小概率个别图床不可达的图片在联网环境下会自动加载。
- 标注「扫描版」的 PDF 无文字层，建议下载后使用 PDF 阅读器查看。
