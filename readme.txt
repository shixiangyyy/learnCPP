learning cpp.
This is a repository for cpp learning.
There may be a few branches according to different learning contents.

//GIT命令记录
cd:寻址，和windows寻址差不多
mkdir：构造目录
pwd：查看当前目录
git init:在当前路径下面创造空的Git repository
git add <filename>:将文件添加到版本库
git commit -m "<mark>":提交文件到仓库，mark中可以做改动描述
git log:查看文件改动记录
git log --pretty=oneline:查看文件改动记录，但是每一次改动仅显示一行，查看提交历史
git reset --hard HEAD^:将文件回退到上一个版本，如果是上上个版本HEAD^^,100个以前的版本，HEAD~100
git reset --hart versionID:将文件回退到指定版本ID
git reflog:查看历史操作日志，从中可以得知历史上有过的各种版本的ID，从而可以结果git reset找到任意版本