# 算法模板

正文按照主题保存在 `chapters/` 中，最终章节顺序由 `pandoc.yaml` 的
`input-files` 明确指定。

在 Arch Linux 上安装构建依赖：

```shell
sudo pacman -S --needed pandoc-cli texlive-xetex texlive-langchinese \
  texlive-latexrecommended texlive-latexextra texlive-fontsrecommended \
  otf-latin-modern
```

生成 PDF：

```shell
make pdf
```

输出文件为 `build/algorithm-templates.pdf`。修改任意章节后再次运行
`make pdf` 即可；如果文件没有变化，Make 不会重复构建。

添加章节时，需要同时完成两件事：

1. 在 `chapters/` 中创建带数字前缀的 Markdown 文件，章节标题从一级标题
   `#` 开始；
2. 把该文件添加到 `pandoc.yaml` 的 `input-files` 中。

文档支持 Obsidian 风格的提示框：`[!note]`、`[!tip]`、
`[!important]`、`[!warning]` 和 `[!caution]`。普通的 Markdown 引用块
也会在 PDF 中显示为带左边框的浅灰色区域。

拆分前的完整文档保存在 `archive/algorithm_templates.md`，仅作为迁移备份，
不会参与 PDF 构建。
