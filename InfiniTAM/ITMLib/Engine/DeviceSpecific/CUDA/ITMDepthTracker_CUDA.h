// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../../ITMDepthTracker.h"

namespace ITMLib
{
	namespace Engine
	{
		class ITMDepthTracker_CUDA : public ITMDepthTracker
		{
		public:
			struct AccuCell;

		private:
			AccuCell *accu_host;
			AccuCell *accu_device;

		protected:
			int ComputeGandH(ITMSceneHierarchyLevel *sceneHierarchyLevel, ITMTemplatedHierarchyLevel<ITMFloatImage> *viewHierarchyLevel,
				Matrix4f approxInvPose, Matrix4f imagePose, bool rotationOnly);

		public:
			ITMDepthTracker_CUDA(Vector2i imgSize, int noHierarchyLevels, int noRotationOnlyLevels, int noICPRunTillLevel, float distThresh, 
				const ITMLowLevelEngine *lowLevelEngine);
			~ITMDepthTracker_CUDA(void);
		};
	}
}
