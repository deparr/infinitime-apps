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
			};
		}
	}
}
