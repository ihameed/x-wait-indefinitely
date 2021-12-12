#include <xcb/xcb.h>
#include <stdlib.h> // free
#include <stdio.h> // fprintf

void
terminate_on_failure(xcb_connection_t * const conn) {
    auto const err = xcb_connection_has_error(conn);
    if (err != 0) {
        fprintf(stderr, "x-wait-indefinitely: connection has error; exiting\n");
        fflush(stderr);
        exit(1);
    }
}

int
main(int, char **) {
    fprintf(stderr, "x-wait-indefinitely: connecting\n");
    fflush(stderr);
    auto const conn = xcb_connect(nullptr, nullptr);
    fprintf(stderr, "x-wait-indefinitely: connected\n");
    fflush(stderr);
    terminate_on_failure(conn);
    xcb_generic_event_t *e = nullptr;
    while ((e = xcb_wait_for_event(conn))) {
        terminate_on_failure(conn);
        free(e);
    }
    xcb_disconnect(conn);
    return 0;
}
