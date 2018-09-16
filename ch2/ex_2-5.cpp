

// 5 我们想实现一种小型语言,用于控制一种简单的绘图包,这种语言由单字母命令组成,有些命令后跟单个数字,例如下面的输入将会绘制出一个矩形:
// P 2 # select pen 2
// D   # pen down
// W 2 # draw west 2cm
// N 1 # then north 1
// E 2 # then east 2
// S 1 # then back south
// U   # pen up
// 请实现解析这种语言的代码,它应该被设计成能简单地增加命令.

// A:以表驱动的方式实现解析器.

typedef struct {
	char cmd;
    int hasArg;
    void (*func)(int, int);
} Command;
static Command cmds[] = {
	{ 'P', ARG, doSelectPen },
	{ 'U', NO_ARG, doPenUp },
	{ 'D', NO_ARG, doSelectPen },
    { 'N', ARG, doPenDir },
    { 'E', ARG, doPenDir },
    { 'S', ARG, doPenDir },
    { 'W', ARG, doPenDir }
};

while (fgets(buff, sizeof(buff). stdin)) {
    Command *cmd = findCommand(*buff);
    if (cmd) {
        int arg = 0;
        if (cmd->hasArg && !getArg(buff+1, &arg)) {
             fprintf(stderr, " '%c' needs am arg\n", *buff*);
             continue;
        }
        cmd->func(*buff, arg);
    }
}

Command *findCommand(int cmd) {
    int i;
    for (i = 0; i < ARRAY_SIZE(cmds); i++) {
        if (cmds[i].cmd == cmd) {
        	return cmds + i;
        }
    }
    fprintf(stderr, "Unknown command '%c'\n", cmd);
    return 0;
}

int getArg(const char *buff, int *result) {
	return sscanf(buff, "%d", result) == 1;
}