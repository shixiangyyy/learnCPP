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

//远程仓库
将本地git版本库与远程版本库进行关联：
git add remote origin git@github.com:shixiangyyy/learnCPP.git
将本地git版本库的全部内容推送到远程库上：
第一次推送：git push -u origin master
后续：git push origin master
因为第一次推送master时，远程库是空的，因此需要加上-u参数，在将本地master推送到远程master上时，将两地master进行关联
因此，后续push或者pull的时候就可以简化命令

//分支管理
查看分支：git branch
创建分支：git branch <branchName>
切换分支：git switch <branchName>
创建+切换：git switch -c <branchName>
合并某分支到当前分支：git merge <branchName>
删除分支：git branch -d <branchName>
