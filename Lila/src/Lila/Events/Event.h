#pragma once

namespace Lila {
	class Event {
	public:
		Event() {}
		virtual ~Event() {}

		bool getCanceled() { return canceled_m; }
		void setCanceled(bool canceled) { canceled_m = canceled; }

	private:
		bool canceled_m = false;
	};
}