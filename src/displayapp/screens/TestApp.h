#pragma once

#include "displayapp/screens/Screen.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class TestApp : public Screen {
      public:
        TestApp(DisplayApp* app);

        ~TestApp() override;

        void Refresh() override;

      private:
         void UpdateArc(lv_task_t* t);

         uint16_t angle;

        lv_obj_t* arc;
        lv_task_t* taskRefresh;
      };
    }
  }
}
