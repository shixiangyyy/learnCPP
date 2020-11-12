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
git reset --hard versionID:将文件回退到指定版本ID
git reset HEAD <filename>:将修改从暂存区回撤，相当于撤销修改的add
git reflog:查看历史操作日志，从中可以得知历史上有过的各种版本的ID，从而可以结果git reset找到任意版本
git restore filename:从工作区撤销修改

//撤销修改的若干种场景
场景1：修改目前只在工作区，还没有被add到暂存区，git restore filename,直接从工作区进行撤销即可
场景2：修改已经被add到暂存区了，但是还没有被commit，git reset HEAD <filename>,先从暂存区回撤到工作区，然后git restore filename,从工作区撤销修改
场景3：修改已经被commit到版本库，像撤销本次修改，git reset --hard versionID/HEAD^等就可以，但是前提是还没有被推送到远程服务器