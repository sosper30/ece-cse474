# How to use Git

Git
===

**Git** is a version control software. You can:
- Save a specific version of your code.
- See differences with previous versions.
- Tag versions.
- Roll back.
- Fork, branch, merge, etc.

**Github** is a way for collaborative teams to work on the same code base.

Github Accounts
===
- Make an account (if you don't have one) [here](https://github.com/join?source=header-home).

Installing Git
===

Mac
---
- Install the Xcode Command Line Tools. These tools include git.

Windows
---
- Go to [https://git-scm.com/download/win](https://git-scm.com/download/win)

Course Code
===

Make a code directory for the course and make it your working directory (use Terminal for MacOs or the Command line for Windows PCs).

Get the code for the course:

```bash
git clone https://github.com/sosper30/ece-cse474
OR
git clone git@github.com:sosper30/ece-cse474
```
Nowadays git uses extra layer of protection when cloning private repositories from github, you need to check [this](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories#cloning-with-https-urls) before cloning any private repository like ece474.

Git setup for homework and labs
===

- Git is a version control system.
- Git should be easy to install on any OS
- Go to Github and make a new repo called 474-Assignments (*with no README*)
- Make the repo **private**
- Invite Professor, TAs and the Grader to your repo
- Follow these steps to invite someone on your git repo        [here](https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-access-to-your-personal-repositories/inviting-collaborators-to-a-personal-repository)
- Our git usernames are listed in ICTE 1.

**I recommend downloading the GitHub App instead of using the terminal**

But if you want, you can do it using the terminal by following these steps:

```
mkdir 474-Assignments
cd 474-Assignments
touch README.md                # touch command creates a new file on the local machine.
git init
git add .
git commit -m "first commit"
git remote add origin https://github.com/yourusername/474-Assignments.git
git push -u origin main
// edit and/or add some files
git add .
git commit -m "Changed some files"
git -u push origin main
```

Go back to Github to see your changes. Your student account should give you the ability to make private repos (so other students will not see your code).

Resulting set up
===

Somewhere on your hard drive you should now have

```bash
  Code/
    ee474/
      README.md
      week_1/
        README.md
    474-Assignments/
      README.md
```

The Github repo for `ee474` is managed by Professor Sep Makhsous. The Github repo for `474-Assignments` is managed by you.

How we will use Git
===

- We will assign exercises each week.
- Push your final code for the assignment in your repository, for example, `474-Assignments/lab_1`.
- After pushing your code to the GitHub, make a **release** so that we can get the notification of that version of your code you uploaded.
- Please follow these steps to make a release:
- Step 1:
- Under Releases section click on create a new release button.
  <img width="757" alt="Screen Shot 2023-01-01 at 11 39 02 AM (1)" src="https://user-images.githubusercontent.com/97274991/210183718-b21b8c82-0ce4-4e87-8798-0bf3e1d9c94a.png">

- Step 2:
- You need to choose a tag before publishing your release, you can make your own tag as shown in the image.
  <img width="757" alt="Screen Shot 2023-01-01 at 11 42 10 AM (1)" src="https://user-images.githubusercontent.com/97274991/210183721-8730f944-93dc-4e8d-ba80-d6e2d99a4971.png">

- Step 3:
- After creating your tag, complete steps 2,3,4 in the image.
  <img width="757" alt="Screen Shot 2023-01-01 at 11 43 23 AM (1)" src="https://user-images.githubusercontent.com/97274991/210183725-c0f8682e-50f9-4eeb-80a0-177160263e18.png">

- We will clone your repo on Sundays mid-day (or there about).
- For C, we will test with our own `unit_test.c` and recompile your code. We will put our scripts up on Github (leaving out some details) for you to use and test your code.
- <span style="color: red">It is important to name your functions and classes exactly as we specify so that the tests will compile.</span>
