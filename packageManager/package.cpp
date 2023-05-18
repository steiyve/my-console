#include <git2.h>
#include <iostream>
using namespace std;
int install() {
  git_repository *repo = NULL;
  git_clone_options options = GIT_CLONE_OPTIONS_INIT;
  const char *url = "https://github.com/username/repo.git";
  const char *path = "repo";
  int error = git_clone(&repo, url, path, &options);
  if (error < 0) {
    cerr << "Error cloning repository: " << giterr_last()->message << endl;
    return 1;
  }
  git_repository_free(repo);
  return 0;
}