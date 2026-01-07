#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <time.h>
#include <stdio.h>

Fl_Box *label;

void update_clock(void*) {
    static char buf[32];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buf, sizeof(buf), "%H:%M:%S", t);

    label->label(buf);
    label->redraw();

    // 1秒ごとに再実行
    Fl::repeat_timeout(1.0, update_clock);
}

int main() {
    Fl_Window *win = new Fl_Window(300, 120, "Digital Clock");

    label = new Fl_Box(20, 20, 260, 80, "");
    label->labelfont(FL_HELVETICA_BOLD);
    label->labelsize(36);
    label->box(FL_FLAT_BOX);

    win->end();
    win->show();

    Fl::add_timeout(0.0, update_clock);

    return Fl::run();
}

