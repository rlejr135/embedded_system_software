#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <linux/input.h>


#define IPC_MSGQ_IM 1245
#define IPC_MSGQ_MO 5421

#define BUFF_SIZE 64

#define POWER_ON 0
#define POWER_OFF 158
#define MODE_UP   115
#define MODE_DOWN 114

#define PROG_MODE_CLOCK   0
#define PROG_MODE_COUNTER 1
#define PROG_MODE_TEXT    2
#define PROG_MODE_DRAW    3
#define PROG_MODE_USER    4

#define KEY_RELEASE 0
#define KEY_PRESS   1



struct input_event ev[BUFF_SIZE];

struct im_msgbuf{

	//****default****//
	long msgtype;

	//****for msg queue****// 
	//****swi[0~8] -> switch 1~ 9****//
	//****key[0] == back, key[1] == 1 vol+, key[2] == vol-****//
	unsigned char swi[9];
	unsigned char key[3];
};

struct mo_msgbuf{
	long msgtype;

	unsigned char poweroff;
	unsigned char mode;

	//clock//

};
//**** input process  ****//
int input_main(key_t);
int input_value(struct im_msgbuf *, int, int);
void input_init_imbuf(struct im_msgbuf *);

//**** main process ****//
int main_main(key_t, key_t);
void main_set_mobuf(struct mo_msgbuf*, int);
int main_mode_change(int, unsigned int);



//**** output process ****//
int output_main(key_t);






//**** program mode 1. Clock ****//

void prog1_construct();
void prog1_destroy();



//**** program mode 2. Counter ****//

void prog2_construct();
void prog2_destroy();



//**** program mode 3. Text ****//

void prog3_construct();
void prog3_destroy();



//**** program mode 4. Draw ****//

void prog4_construct();
void prog4_destroy();



//**** program mode 5. User ****//

void prog5_construct();
void prog5_destroy();


