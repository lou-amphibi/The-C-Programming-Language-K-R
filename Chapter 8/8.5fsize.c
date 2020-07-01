void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: нет доступа к %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld%s\n", stbuf.st_size, stbuf.st_dev, stbuf.st_ino, stbuf.st_mode, stbuf.st_nlink, stbuf.st_uid, stbuf.st_gid, stbuf.st_atime, stbuf.st_mtime, name);
}