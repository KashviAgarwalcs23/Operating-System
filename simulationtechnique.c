#include <stdio.h>

int main() {
    int disk_size, num_files;

    // 1. Get disk size and number of files
    printf("Enter total disk size (number of blocks): ");
    scanf("%d", &disk_size);
    printf("Enter number of files: ");
    scanf("%d", &num_files);

    int disk[disk_size];      // 0 = free, 1 = occupied
    for (int i = 0; i < disk_size; i++)
        disk[i] = 0;

    // 2. For each file: get start and size, then try to allocate
    for (int f = 0; f < num_files; f++) {
        int start, size;
        printf("File %d - Enter desired start block: ", f + 1);
        scanf("%d", &start);
        printf("File %d - Enter size (number of blocks): ", f + 1);
        scanf("%d", &size);

        // Validate request
        if (start < 0 || start + size > disk_size) {
            printf("File %d: invalid range [%d .. %d)\n",
                   f+1, start, start+size);
            continue;
        }

        // Check if all blocks in [start, start+size) are free
        int can_alloc = 1;
        for (int i = start; i < start + size; i++) {
            if (disk[i]) {
                can_alloc = 0;
                break;
            }
        }

        // 3. Report and mark or fail
        if (can_alloc) {
            for (int i = start; i < start + size; i++)
                disk[i] = 1;
            printf("File %d allocated at blocks [%d .. %d)\n",
                   f+1, start, start+size);
        } else {
            printf("File %d: cannot allocate at [%d .. %d) (space occupied)\n",
                   f+1, start, start+size);
        }
    }

    return 0;
}
