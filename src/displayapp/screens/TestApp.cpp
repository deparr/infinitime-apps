#include "displayapp/screens/TestApp.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

TestApp::TestApp(DisplayApp* app) : Screen(app) {
  static lv_style_t bg_style, indic_style;
  lv_style_init(&bg_style); lv_style_init(&indic_style);
  lv_style_set_line_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x8e, 0xc0, 0x7c));
  lv_style_set_line_color(&indic_style, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xfb, 0x49, 0x34));

  angle = 271;
  arc = lv_arc_create(lv_scr_act(), nullptr);
  lv_arc_set_type(arc, LV_ARC_TYPE_NORMAL);
  lv_arc_set_bg_angles(arc, 0, 360);
  lv_arc_set_angles(arc, 270, angle);
  lv_obj_set_size(arc, 220, 220);
  lv_obj_align(arc, nullptr, LV_ALIGN_CENTER, 0, 0);

  lv_obj_add_style(arc, LV_ARC_PART_BG, &bg_style);
  lv_obj_add_style(arc, LV_ARC_PART_INDIC, &indic_style);
  
  taskRefresh = lv_task_create(RefreshTaskCallback, 40, LV_TASK_PRIO_MID, this);

}

TestApp::~TestApp() {
  lv_obj_clean(lv_scr_act());
  lv_task_del(taskRefresh);
}

void TestApp::Refresh() {
  angle += 6;

  if (angle >= 270 + 360) {
    angle = 270;
  }

  lv_arc_set_end_angle(arc, angle);

}
