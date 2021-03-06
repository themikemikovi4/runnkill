#include <graphics/objects/field.h>
#include <graphics/gl.h>
#include <string.h>
#include <assert.h>

int field_w, field_h;
unsigned int field_vbo;
vertex3d *field_vbo_data;

void init_field_object(int w, int h, int **bounds) {
    field_w = w;
    field_h = h;
    field_vbo_data = malloc(w * h * 4 * 6 * sizeof(vertex3d));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (bounds[i][j] >= 0) {
                vertex3d box[4 * 6] = {
                    {{i + 0,           -1, j + 0}, {0, 0}, {-1, 0, 0}},
                    {{i + 0, bounds[i][j], j + 0}, {0, 1}, {-1, 0, 0}},
                    {{i + 0, bounds[i][j], j + 1}, {1, 1}, {-1, 0, 0}},
                    {{i + 0,           -1, j + 1}, {1, 0}, {-1, 0, 0}},

                    {{i + 1,           -1, j + 0}, {0, 0}, {+1, 0, 0}},
                    {{i + 1, bounds[i][j], j + 0}, {0, 1}, {+1, 0, 0}},
                    {{i + 1, bounds[i][j], j + 1}, {1, 1}, {+1, 0, 0}},
                    {{i + 1,           -1, j + 1}, {1, 0}, {+1, 0, 0}},

                    {{i + 0,              -1, j + 0}, {0, 0}, {0, -1, 0}},
                    {{i + 1,              -1, j + 0}, {0, 1}, {0, -1, 0}},
                    {{i + 1,              -1, j + 1}, {1, 1}, {0, -1, 0}},
                    {{i + 0,              -1, j + 1}, {1, 0}, {0, -1, 0}},

                    {{i + 0, bounds[i][j], j + 0}, {0, 0}, {0, +1, 0}},
                    {{i + 1, bounds[i][j], j + 0}, {0, 1}, {0, +1, 0}},
                    {{i + 1, bounds[i][j], j + 1}, {1, 1}, {0, +1, 0}},
                    {{i + 0, bounds[i][j], j + 1}, {1, 0}, {0, +1, 0}},

                    {{i + 0,              -1, j + 0}, {0, 0}, {0, 0, -1}},
                    {{i + 1,              -1, j + 0}, {0, 1}, {0, 0, -1}},
                    {{i + 1, bounds[i][j], j + 0}, {1, 1}, {0, 0, -1}},
                    {{i + 0, bounds[i][j], j + 0}, {1, 0}, {0, 0, -1}},

                    {{i + 0,              -1, j + 1}, {0, 0}, {0, 0, +1}},
                    {{i + 1,              -1, j + 1}, {0, 1}, {0, 0, +1}},
                    {{i + 1, bounds[i][j], j + 1}, {1, 1}, {0, 0, +1}},
                    {{i + 0, bounds[i][j], j + 1}, {1, 0}, {0, 0, +1}},
                };
                memcpy(field_vbo_data + 4 * 6 * (i * h + j), box, 4 * 6 * sizeof(vertex3d));
            }
        }
    }
    glGenBuffers(1, &field_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, field_vbo);
    glBufferData(GL_ARRAY_BUFFER, w * h * 4 * 6 * sizeof(vertex3d), field_vbo_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void free_field_object(void) {
    free(field_vbo_data);
    glDeleteBuffers(1, &field_vbo);
}

draw_obj make_draw_field(material_t _material) {
    draw_obj ret;
    ret.mat_m = make_mat4();
    id_mat4(ret.mat_m);
    ret.mode = GL_QUADS;
    ret.vbo = field_vbo;
    ret.ibo = NULL;
    ret.count = field_w * field_h * 4 * 6;
    ret.material = _material;
    ret.free_mat_m = 0;
    ret.free_ibo = 0;
    return ret;
}

draw_obj make_draw_subfield(int x1, int y1, int x2, int y2, material_t _material) {
    draw_obj ret;
    ret.mat_m = make_mat4();
    id_mat4(ret.mat_m);
    ret.mode = GL_QUADS;
    ret.vbo = field_vbo;
    ret.ibo = malloc((x2 - x1) * (y2 - y1) * 4 * 6 * sizeof(unsigned int));
    int idx = 0;
    for (int i = x1; i < x2; ++i) {
        for (int j = y1; j < y2; ++j) {
            for (int k = 0; k < 4 * 6; ++k) {
                ((unsigned int *) ret.ibo)[idx++] = 4 * 6 * (i * field_h + j) + k;
            }
        }
    }
    ret.count = (x2 - x1) * (y2 - y1) * 4 * 6;
    ret.material = _material;
    ret.free_mat_m = 0;
    ret.free_ibo = 0;
    return ret;
}
